# Created by: Geoffrey Mainland <mainland@apeiron.net>
# $FreeBSD$

PORTNAME=	antlr
PORTVERSION=	2.7.7
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr2.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition

CONFLICTS=	pccts-[0-9]*

USES=		gmake
USE_JAVA=	yes
JAVA_VERSION=	1.6+

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

OPTIONS_DEFINE=	PYTHON DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
PORTDOCS+=	python-runtime.html
ANTLR_PYTHON=	${WRKSRC}/lib/python
.endif

post-extract:
	(cd ${WRKSRC} && ${CP} antlr.jar antlrall.jar)

post-configure:
.if ${PORT_OPTIONS:MPYTHON}
	(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py config)
.endif

.if defined(WITH_BUILT_JAVA_LIB)
pre-build:
	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool build)
	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool jar)
.endif

.if ${PORT_OPTIONS:MPYTHON}
post-build:
	(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py build && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${ANTLR_PYTHON})
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/antlr.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${STAGEDIR}${PREFIX}/bin/antlr
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/cpp/antlr/*.hpp \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/cpp/src/libantlr.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.if ${PORT_OPTIONS:MPYTHON}
	@(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py install --root=${STAGEDIR})
.endif

.include <bsd.port.mk>
