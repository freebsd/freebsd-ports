# New ports collection makefile for:   libreadline-java
# Date created:                21 September 2007
# Whom:                        Martin Kammerhofer <mkamm@gmx.net>
#
# $FreeBSD$
#

PORTNAME=		jline
PORTVERSION=		0.9.91
PORTREVISION=	1
CATEGORIES=		devel java
MASTER_SITES=		SF

MAINTAINER=	mkamm@gmx.net
COMMENT=	JLine is a Java library for handling console input

PKGMESSAGE=	${WRKDIR}/pkg-message
USE_JAVA=	yes
USE_ZIP=	yes
OPTIONS=	JLINEPATCH "Allow ConsoleRunner customized completion" OFF
JLINEJAR=	${WRKSRC}/jline-${PORTVERSION}.jar

.include <bsd.port.pre.mk>

# Update jar archive with patched jline.ConsoleRunner class.
do-build:
.ifdef(WITH_JLINEPATCH)
	${JAVAC} -classpath ${JLINEJAR} \
		${WRKSRC}/src/src/main/java/jline/ConsoleRunner.java
	${JAR} uvf ${JLINEJAR} -C ${WRKSRC}/src/src/main/java \
		jline/ConsoleRunner.class
.endif

do-install:
	${INSTALL_DATA} ${JLINEJAR} ${JAVAJARDIR}
	${LN} -nfs ${JAVAJARDIR}/jline-${PORTVERSION}.jar \
		   ${JAVAJARDIR}/jline.jar
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
