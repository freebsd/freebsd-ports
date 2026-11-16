PORTNAME=	cppinsights
DISTVERSIONPREFIX=	v_
DISTVERSION=	23.1
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	C++ Insights - See your source code with the eyes of a compiler
WWW=		https://github.com/andreasfertig/cppinsights

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake llvm:min=23,lib
USE_GITHUB=	yes
GH_ACCOUNT=	andreasfertig

CMAKE_ARGS=	-DLLVM_CONFIG_PATH="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config"

CXXFLAGS=	-pthread
LDFLAGS=	-pthread

PLIST_FILES=	bin/insights \
		share/bash-completion/completions/insights \
		share/fish/vendor_completions.d/insights.fish \
		share/zsh/site-functions/_insights

.include <bsd.port.mk>
