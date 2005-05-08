# New ports collection makefile for:	phpsview
# Date created:				17 April 2005
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	phpsview
PORTVERSION=	9.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.smcc.demon.nl/webcam/
MASTER_SITE_SUBDIR=	${REALNAME}
DISTNAME=	${REALNAME}-${PORTVERSION}

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES=	${DISTNAME}-bsd-0.03.patch.gz
PATCH_DIST_STRIP=	-p2

MAINTAINER=	mistral@imasy.or.jp
COMMENT=	Philips USB Cameras Utilities for NetBSD/FreeBSD

REALNAME=	pwc
WRKSRC=		${WRKDIR}/${DISTNAME}/2.4

.if defined(WITHOUT_X11)
COMPONENTS=	phpsshot
.else
USE_GNOME=	imlib gtk12
COMPONENTS=	phpsshot phpsview
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

.include <bsd.port.mk>
