# New ports collection makefile for:   soundtracker
# Date created:        28 November 1999
# Whom:                kzentner
#
# $FreeBSD$
#

PORTNAME=	soundtracker
PORTVERSION=	0.6.8
CATEGORIES=	audio gnome
MASTER_SITES=	http://www.soundtracker.org/dl/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mod player/tracking tool which supports XM and MOD formats

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	esound gdkpixbuf gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomelibs gnomeprefix
CONFIGURE_ARGS+=	--enable-gnome
DATADIR=	${PREFIX}/share/gnome/${PORTNAME}
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=		jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| install-exec-local||g'
	@${REINPLACE_CMD} -e 's|-pthread -ldl||g' ${WRKSRC}/configure

pre-build:
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt -c -o ja.gmo ja.po
.endif

.include <bsd.port.post.mk>
