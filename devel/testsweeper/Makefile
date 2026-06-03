PORTNAME=	testsweeper
DISTVERSION=	2025.05.28
CATEGORIES=	devel
MASTER_SITES=	https://github.com/icl-utk-edu/testsweeper/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ testing framework for parameter sweeps
WWW=		https://github.com/icl-utk-edu/testsweeper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes

CMAKE_ON=	testsweeper_install
CMAKE_OFF=	build_tests

.include <bsd.port.mk>
