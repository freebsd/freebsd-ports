# New ports collection makefile for:	openexr_ctl
# Date created:				2007-10-09
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	openexr_ctl
PORTVERSION=	1.0.0
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	openexr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simplified OpenEXR interface to CTL

LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		IlmCtl.2:${PORTSDIR}/graphics/ampasCTL

USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.if defined(PACKAGE_BUILDING)
pre-install:	test
.endif

.include <bsd.port.mk>
