# Created by: Martin Kammerhofer <mkamm@gmx.net>
# $FreeBSD$

PORTNAME=		jline
PORTVERSION=		0.9.94
CATEGORIES=		devel java
MASTER_SITES=		SF

MAINTAINER=	mkamm@gmx.net
COMMENT=	JLine is a Java library for handling console input

LICENSE=	BSD

PKGMESSAGE=	${WRKDIR}/pkg-message
USE_JAVA=	yes
USE_ZIP=	yes
OPTIONS_DEFINE=	JLINEPATCH
JLINEPATCH_DESC=	Allow ConsoleRunner customized completion
JLINEJAR=	${WRKSRC}/jline-${PORTVERSION}.jar

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
	${INSTALL_DATA} ${JLINEJAR} ${JAVAJARDIR}
	${LN} -nfs ${JAVAJARDIR}/jline-${PORTVERSION}.jar \
		   ${JAVAJARDIR}/jline.jar
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/apidocs ${WRKSRC}/examples ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/JLineCompleter.py ${DOCSDIR}/examples
	${INSTALL_DATA} ${FILESDIR}/jython.sh ${DOCSDIR}/examples
.endif

post-install:
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' -- \
		${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

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
		${FIND} ./apidocs ./examples -type d | ${SORT} -r \
			| ${SED} -e 's/^/@dirrm /';	\
		${ECHO_CMD} "@dirrm %%DOCSDIR%%" ;	\
	) | ${SED} -e 's/\.\//%%DOCSDIR%%\//' -e 's/^/%%PORTDOCS%%/' >>${PLIST}

.include <bsd.port.mk>
