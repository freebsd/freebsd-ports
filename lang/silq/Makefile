PORTNAME=	silq
PORTVERSION=	20250624
PORTREVISION=	1
CATEGORIES=	lang math science
DIST_SUBDIR=	silq

MAINTAINER=	se@FreeBSD.org
COMMENT=	Silq from ETH Zuerich
WWW=		https://silq.ethz.ch/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	unknown status of the D language compiler (lang/ldc) on ${ARCH}

BUILD_DEPENDS=	ldmd2:lang/ldc

USE_GITHUB=	yes

GH_TUPLE=	eth-sri:silq:92a6f80 \
		tgehr:ast:3b355c8:ast/ast \
		tgehr:util:68629c1:util/util

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

do-build:
		cd ${WRKSRC}; ldmd2 -O -inline -J. -Jlibrary *.d ast/*.d util/*.d -of=silq

do-test:
		cd ${WRKSRC}/test; ldmd2 -O runtests.d -of=runtests
		cd ${WRKSRC}/test; ./runtests

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/silq ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MEXAMPLES}
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "-name *\.slq"
.endif

.include <bsd.port.mk>
