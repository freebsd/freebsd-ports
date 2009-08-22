# New ports collection makefile for:	ampasCTL
# Date created:				2007-10-08
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ampasCTL
PORTVERSION=	1.4.0
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME:L}/ctl/${PORTVERSION}
DISTNAME=	ctl-${PORTVERSION}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Color Transformation Language interpreter

LIB_DEPENDS=	Half.6:${PORTSDIR}/graphics/ilmbase

USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22

test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.if defined(PACKAGE_BUILDING)
pre-install:	test
.endif

.include <bsd.port.mk>
