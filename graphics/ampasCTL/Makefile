# New ports collection makefile for:	ampasCTL
# Date created:				2007-10-08
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ampasCTL
PORTVERSION=	1.4.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME:L}/ctl/ctl-${PORTVERSION}/
DISTNAME=	ctl-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Color Transformation Language interpreter

LICENSE=	BSD

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase

USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

PORTDOCS=	AUTHORS ChangeLog NEWS README

.include <bsd.port.options.mk>

test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.if defined(PACKAGE_BUILDING)
pre-install:	test
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
