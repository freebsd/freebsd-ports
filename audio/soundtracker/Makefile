# New ports collection makefile for:   soundtracker
# Date created:        28 November 1999
# Whom:                kzentner
#
# $FreeBSD$
#

PORTNAME=	soundtracker
PORTVERSION=	0.6.7
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

.if ${HAVE_GNOME:Mgnomelibs}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomelibs gnomeprefix
CONFIGURE_ARGS+=	--enable-gnome
DATADIR=	${PREFIX}/share/gnome/${PORTNAME}
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| install-exec-local||g'

.include <bsd.port.post.mk>
