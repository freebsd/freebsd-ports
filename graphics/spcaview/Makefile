# New ports collection makefile for:    spca5xx
# Date created:                         21 March 2005
# Whom:                                 Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	spca5xx
PORTVERSION=	20060402
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://mxhaard.free.fr/spca50x/Download/ \
		http://mxhaard.free.fr/spca50x/Download/oldrelease/

PATCH_SITES=	http://www.medias.ne.jp/~takam/bsd/
PATCHFILES=	spca5xx-bsd-0.6b.patch.gz
PATCH_DIST_STRIP=	-p3

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	USB Cameras based SPCA5xx Utilities

WRKSRC=		${WRKDIR}/${DISTNAME}/drivers/usb

.if defined(WITHOUT_X11)
COMPONENTS=	spca5shot
.else
USE_GNOME=	imlib gtk12
COMPONENTS=	spca5shot spca5view
.endif

MAN1=		${COMPONENTS:S/$/.1/}
MANCOMPRESSED=	yes
PLIST_FILES=	${COMPONENTS:S/^/bin\//}

MAKE_ARGS+=	MANDIR=${MANPREFIX}/man/man

do-build:
.for component in ${COMPONENTS}
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} Makefile.${component} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for component in ${COMPONENTS}
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} Makefile.${component} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
