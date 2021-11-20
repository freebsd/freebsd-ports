PORTNAME=	silq
PORTVERSION=	20211117
CATEGORIES=	lang math science

MAINTAINER=	se@FreeBSD.org
COMMENT=	Silq from ETH Zuerich

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	unknown status of the D language compiler (lang/ldc) on ${ARCH}

BUILD_DEPENDS=	ldmd2:lang/ldc \
		llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}

USE_GITHUB=	yes

GH_TUPLE=	eth-sri:silq:1bc7ece \
		tgehr:ast:7c26e76:ast/ast \
		tgehr:util:7e9f0ce:util/util

OPTIONS_DEFINE=	EXAMPLES

LLVM_VERSION=	10

.include <bsd.port.options.mk>

do-build:
		cd ${WRKSRC}; ldmd2 -O -inline -J. -Jlibrary *.d ast/*.d util/*.d -linker=lld${LLVM_VERSION} -of=silq

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/silq ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MEXAMPLES}
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "-name *\.slq"
.endif

.include <bsd.port.mk>
