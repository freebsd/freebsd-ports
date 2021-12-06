PORTNAME=	getoptions
PORTVERSION=	3.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Elegant option parser for shell scripts

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ko1nksm

PORTDOCS=	*
PORTEXAMPLES=	*

TESTS_EXAMPLES=	advanced.sh basic.sh bench.sh example.sh \
	parser_definition.sh prehook.sh subcmd.sh

PLIST_FILES=	bin/getoptions \
				bin/gengetoptions

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

NO_ARCH=	yes

do-build:
	cd ${WRKSRC} && ${MAKE} build

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.md CHANGELOG.md \
		docs/References.md docs/Workarounds.md \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${TESTS_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
