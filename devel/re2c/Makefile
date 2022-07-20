PORTNAME=	re2c
DISTVERSION=	2.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/skvadrik/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Lexer generator for C, C++ and Go with a focus on generating fast code

LICENSE=	PD

TEST_DEPENDS=	bash:shells/bash

USES=		cmake cpe python:3.6+,test shebangfix tar:xz

TEST_TARGET=	check
SHEBANG_FILES=	test/posix_captures/.run/__run.sh \
		test/posix_captures/.gen/__gen.sh \
		test/__run_unicode_tests.sh

OPTIONS_DEFINE=		DOCS EXAMPLES LIBRE2C RE2GO
OPTIONS_DEFAULT=	RE2GO
OPTIONS_SUB=		yes

LIBRE2C_DESC=		Build libre2c (Experimental)
RE2GO_DESC=		Build RE2GO (identical to re2c --lang go)

DOCS_BUILD_DEPENDS=	bison:devel/bison \
			rst2man:textproc/py-docutils
DOCS_CMAKE_BOOL=	RE2C_REBUILD_DOCS
LIBRE2C_CMAKE_BOOL=	RE2C_BUILD_LIBS BUILD_SHARED_LIBS
RE2GO_CMAKE_BOOL=	RE2C_BUILD_RE2GO

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
