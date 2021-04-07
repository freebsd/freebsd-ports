PORTNAME=	ansilove
PORTVERSION=	4.1.5
CATEGORIES=	graphics textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	ANSI / ASCII art to PNG converter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libansilove.so:graphics/libansilove

USE_GITHUB=	yes

USES=		cmake
TEST_TARGET=	test

PORTDOCS=	AUTHORS ChangeLog README.md THANKS
PORTEXAMPLES=	*

PLIST_FILES=	bin/ansilove \
		man/man1/ansilove.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-test:
	@cd ${WRKSRC}/examples/ && for f in */*.ans; do \
		${MKDIR} -p ${WRKDIR}/test/`dirname "$$f"`; \
		${BUILD_WRKSRC}/${PORTNAME} -o "${WRKDIR}/test/$$f.png" "$$f"; \
		${FILE} "${WRKDIR}/test/$$f.png" | ${GREP} -q 'PNG'; \
	done

.include <bsd.port.mk>
