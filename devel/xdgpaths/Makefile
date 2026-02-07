PORTNAME=	xdgpaths
PORTVERSION=	0.2.5
PORTREVISION=	6
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	XDG Base Directory Specification implementation in D lang
WWW=		https://github.com/FreeSlave/xdgpaths

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libisfreedesktop.a:devel/isfreedesktop

USE_GITHUB=	yes
GH_ACCOUNT=	FreeSlave

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d
DC=		${PREFIX}/bin/ldmd2

do-build:
	@cd ${WRKSRC} && \
		${SETENV} DUB_HOME=${WRKDIR}/dub_home DC=${DC} ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libxdgpaths.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/source && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
