PORTNAME=	antlr
PORTVERSION=	2.7.7
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	https://www.antlr2.org/download/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS=	pccts

USES=		compiler:c++11-lang gmake
USE_JAVA=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}" CLASSPATH="${PORT_CLASSPATH}"
CONFIGURE_ARGS=	--disable-csharp --prefix=${PREFIX}

PORT_CLASSPATH=	${WRKSRC}/antlrall.jar:.

SUB_FILES=	antlr.sh

PORTDOCS=	ANTLRException.gif closure.gif cpp-runtime.html \
		csharp-runtime.html err.html glossary.html hidden.stream.gif \
		index.html inheritance.html j-guru-blue.jpg jguru-logo.gif \
		lexer.html lexer.to.parser.tokens.gif logo.gif metalang.html \
		optional.gif options.html posclosure.gif runtime.html sor.html \
		stream.perspectives.gif stream.selector.gif \
		stream.splitter.gif streams.html subrule.gif trees.html \
		vocab.html

OPTIONS_DEFINE=	DOCS

post-extract:
	(cd ${WRKSRC} && ${CP} antlr.jar antlrall.jar)

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/antlr.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${STAGEDIR}${PREFIX}/bin/antlr
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/cpp/antlr/*.hpp \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/cpp/src/libantlr.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
