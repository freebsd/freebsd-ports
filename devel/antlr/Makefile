# New ports collection makefile for:	antlr
# Date created:		5 July 2002
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	antlr
PORTVERSION=	2.7.4
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

CONFLICTS=	pccts*

USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}" JAVA="${JAVA}" CLASSPATH="${PORT_CLASSPATH}"

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
PLIST_FILES=	bin/antlr %%JAVAJARDIR%%/antlr.jar

.include <bsd.port.pre.mk>

post-extract:
	(cd ${WRKSRC} && ${CP} antlr.jar antlrall.jar)
	${CHMOD} -R +w ${WRKSRC}

post-configure:
	@${SED} "s|%%JAVAJARDIR%%|${JAVAJARDIR}| ; s|%%LOCALBASE%%|${LOCALBASE}| ; s|%%JAVA_VERSION%%|${JAVA_VERSION}|" ${FILESDIR}/antlr.sh >${WRKDIR}/antlr.sh

.if defined(WITH_BUILT_JAVA_LIB)
pre-build:
	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool build)
	(cd ${WRKSRC} && ${JAVA} -classpath "${PORT_CLASSPATH}" antlr.build.Tool jar)
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/antlr.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing antlr script as ${PREFIX}/bin/${PORTNAME}..."
	@${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${PREFIX}/bin/antlr
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} ">> Installing native files..."
	@(cd ${WRKSRC}/lib/cpp && ${GMAKE} install)
	@${ECHO_MSG} "   [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${ECHO_MSG} -n ">> Installing examples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} ${EXAMPLES} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${FIND} -s ${EXAMPLES:S,^,${WRKSRC}/examples/,} -not -type d | \
		${SED} -ne 's,^${WRKSRC}/examples,${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${EXAMPLES:S,^,${WRKSRC}/examples/,} -type d | \
		${SED} -ne 's,^${WRKSRC}/examples,@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO} "@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
