PORTNAME=	cppinsights
DISTVERSIONPREFIX=	v_
DISTVERSION=	17.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	C++ Insights - See your source code with the eyes of a compiler
WWW=		https://github.com/andreasfertig/cppinsights

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake llvm:min=17,lib
USE_GITHUB=	yes
GH_ACCOUNT=	andreasfertig

CMAKE_ARGS=	-DLLVM_CONFIG_PATH="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config"

PLIST_FILES=	bin/insights

.include <bsd.port.mk>
