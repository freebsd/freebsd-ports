# New ports collection makefile for:   soundtracker
# Date created:        28 November 1999
# Whom:                kzentner
#
# $FreeBSD$
#

PORTNAME=	soundtracker
PORTVERSION=	0.6.6
CATEGORIES=	audio gnome
MASTER_SITES=	http://www.soundtracker.org/dl/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
USE_GNOME=	esound gdkpixbuf
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500034
CONFIGURE_ARGS+=	--disable-asm
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomelibs gnomeprefix gnomehack
CONFIGURE_ARGS+=	--enable-gnome
PLIST_SUB+=	DATADIR="share/gnome"
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	DATADIR="share"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| install-exec-local||g'

.include <bsd.port.post.mk>
