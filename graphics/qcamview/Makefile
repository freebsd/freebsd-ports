# New ports collection makefile for:	qcamview
# Date created:				16 April 2004
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	qcamview
PORTVERSION=	0.40d
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${REALNAME}
DISTNAME=	${REALNAME}-${PORTVERSION}

PATCH_SITES=	http://www.medias.ne.jp/~takam/bsd/
PATCHFILES=	${REALNAME}-bsd-0.04.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	Logitech Quickcam Express USB Utilities for NetBSD/FreeBSD

REALNAME=	qce-ga
WRKSRC=		${WRKDIR}/${REALNAME}-${PORTVERSION}

.if defined(WITHOUT_X11)
COMPONENTS=	qcamshot
.else
USE_GNOME=	imlib gtk12
COMPONENTS=	qcamshot qcamview
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
