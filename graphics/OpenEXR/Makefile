# New ports collection makefile for:	OpenEXR
# Date created:				2003/01/26
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	OpenEXR
PORTVERSION=	1.6.0
PORTREVISION=	0
DISTNAME=	${PORTNAME:L}-${PORTVERSION}
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A high dynamic-range (HDR) image file format

LIB_DEPENDS=	Half.6:${PORTSDIR}/graphics/ilmbase

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--enable-imfexamples

WRKSRC=		${WRKDIR}/${DISTNAME}

test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
.if ${ARCH} != sparc64 || ${OSVERSION} >= 700055
pre-install:	test
.endif
.endif

.include <bsd.port.post.mk>
