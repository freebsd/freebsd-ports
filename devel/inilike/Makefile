PORTNAME=	inilike
PORTVERSION=	1.2.1
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	D library for parsing ini-like files used in Freedesktop systems
WWW=		https://github.com/FreeSlave/inilike

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub

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
	${INSTALL_DATA} ${WRKSRC}/lib/libinilike.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/source && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
