# Created by: Martin Kammerhofer <mkamm@gmx.net>
# $FreeBSD$

PORTNAME=	jline
PORTVERSION=	0.9.94
CATEGORIES=	devel java
MASTER_SITES=	SF

MAINTAINER=	mkamm@gmx.net
COMMENT=	Java library for handling console input

LICENSE=	BSD4CLAUSE

USES=		zip
USE_JAVA=	yes
OPTIONS_DEFINE=	JLINEPATCH DOCS
JLINEPATCH_DESC=	Allow ConsoleRunner customized completion
JLINEJAR=	${WRKSRC}/jline-${PORTVERSION}.jar
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

# Update jar archive with patched jline.ConsoleRunner class.
do-build:
.if ${PORT_OPTIONS:MJLINEPATCH}
	${JAVAC} -classpath ${JLINEJAR} \
		${WRKSRC}/src/src/main/java/jline/ConsoleRunner.java
	${JAR} uvf ${JLINEJAR} -C ${WRKSRC}/src/src/main/java \
		jline/ConsoleRunner.class
.endif

do-install:
	${INSTALL_DATA} ${JLINEJAR} ${STAGEDIR}${JAVAJARDIR}
	${LN} -nfs jline-${PORTVERSION}.jar \
		   ${STAGEDIR}${JAVAJARDIR}/jline.jar
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/apidocs ${WRKSRC}/examples ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/JLineCompleter.py ${STAGEDIR}${DOCSDIR}/examples
	${INSTALL_DATA} ${FILESDIR}/jython.sh ${STAGEDIR}${DOCSDIR}/examples
.endif

# Next rule is for maintainer use only: Automatically (re)create the pkg-plist.
plist:
	@test -e ${CONFIGURE_COOKIE} || { \
		${ECHO_MSG} >&2 "do 'make configure' first!"; exit 64; }
	${ECHO_CMD} "%%JAVAJARDIR%%/jline-${PORTVERSION}.jar" >${PLIST}
	${ECHO_CMD} "%%JAVAJARDIR%%/jline.jar" >>${PLIST}
	( \
		cd ${WRKSRC} || exit; \
		${FIND} ./apidocs ./examples -type f | ${SORT};	\
		${ECHO_CMD} "./examples/JLineCompleter.py";	\
		${ECHO_CMD} "./examples/jython.sh";		\
	) | ${SED} -e 's/\.\//%%DOCSDIR%%\//' -e 's/^/%%PORTDOCS%%/' >>${PLIST}

.include <bsd.port.mk>
