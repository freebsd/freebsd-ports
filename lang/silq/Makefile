# $FreeBSD$

PORTNAME=	silq
PORTVERSION=	20200621
CATEGORIES=	lang math science

MAINTAINER=	se@FreeBSD.org
COMMENT=	Silq from ETH Zürich

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	unknown status of the D language compiler (lang/ldc) on ${ARCH}

BUILD_DEPENDS=	ldmd2:lang/ldc

USE_GITHUB=	yes

GH_TUPLE=	eth-sri:silq:7331c54 \
		tgehr:ast:3018b4b:ast/ast \
		tgehr:util:27168af:util/util

OPTIONS_DEFINE=	EXAMPLES

do-build:
		cd ${WRKSRC}; ldmd2 -O -inline -J. -Jlibrary *.d ast/*.d util/*.d -linker=lld -of=silq

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/silq ${STAGEDIR}${PREFIX}/bin/
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "-name *\.slq"

.include <bsd.port.mk>
