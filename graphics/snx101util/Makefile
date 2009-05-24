# New ports collection makefile for:	snx101util
# Date created:				23 November 2004
# Whom:					Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snx101util
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.medias.ne.jp/~takam/bsd/

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Image capture programs for Webcam based SN9C101

.if defined(WITHOUT_X11)
COMPONENTS=	snx101shot
.else
USE_GNOME=	imlib gtk12
COMPONENTS=	snx101shot snx101view
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
BROKEN=	does not build
.endif

.include <bsd.port.post.mk>
