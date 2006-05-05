# New ports collection makefile for:	antlr
# Date created:		5 July 2002
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	antlr
PORTVERSION=	2.7.6
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr.org/download/

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	ANother Tool for Language Recognition

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

CONFLICTS=	pccts-[0-9]*

USE_GCC=	3.2+
USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

OPTIONS=	PYTHON "Include Python runtime support" off

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}" CLASSPATH="${PORT_CLASSPATH}"
CONFIGURE_ARGS=	--disable-csharp

PORT_CLASSPATH=	${WRKSRC}/antlrall.jar:.

EXAMPLES=	cpp java
.if !defined(NOPORTDOCS)
PORTDOCS=	ANTLRException.gif closure.gif cpp-runtime.html \
		csharp-runtime.html err.html glossary.html hidden.stream.gif \
		index.html inheritance.html j-guru-blue.jpg jguru-logo.gif \
		lexer.html lexer.to.parser.tokens.gif logo.gif metalang.html \
		optional.gif options.html posclosure.gif runtime.html sor.html \
		stream.perspectives.gif stream.selector.gif \
		stream.splitter.gif streams.html subrule.gif trees.html \
		vocab.html
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	2.2+
# we need to manually include this, because USE_PYTHON is defined
# after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.python.mk"
PORTDOCS+=	python-runtime.html
ANTLR_PYTHON=	${WRKSRC}/lib/python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

post-extract:
	(cd ${WRKSRC} && ${CP} antlr.jar antlrall.jar)

post-configure:
	${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|' \
	-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	-e 's|%%JAVA_VERSION%%|${JAVA_VERSION}|' ${FILESDIR}/antlr.sh > ${WRKDIR}/antlr.sh
.if defined(WITH_PYTHON)
	(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py config)
.endif

.if defined(WITH_BUILT_JAVA_LIB)
pre-build:
	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool build)
	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool jar)
.endif

.if defined(WITH_PYTHON)
post-build:
	(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py build && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${ANTLR_PYTHON})
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/antlr.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing antlr script as ${PREFIX}/bin/${PORTNAME}..."
	@${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${PREFIX}/bin/antlr
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} ">> Installing native files..."
	@(cd ${WRKSRC}/lib/cpp && ${GMAKE} install)
	@${ECHO_MSG} "   [ DONE ]"
.if defined(WITH_PYTHON)
	@${ECHO_MSG} -n ">> Installing Python runtime files..."
	@(cd ${ANTLR_PYTHON} && ${PYTHON_CMD} setup.py install)
	@${ECHO_MSG} "   [ DONE ]"
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
