# Created by: ijliao
# $FreeBSD$

PORTNAME=	clojure
PORTVERSION=	1.8.0
CATEGORIES=	lang lisp java
MASTER_SITES=	http://repo1.maven.org/maven2/org/clojure/clojure/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	jan0sch@mykolab.com
COMMENT=	Dynamic programming language for the JVM

LICENSE=	EPL

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
SUB_FILES=	clojure-bin

OPTIONS_DEFINE=	JLINE
OPTIONS_DEFAULT=	JLINE
JLINE_DESC=	jline support for the REPL

PLIST_FILES=	bin/clojure \
		%%JAVAJARDIR%%/clojure.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJLINE}
RUN_DEPENDS+=	jline>=0.9.91:devel/jline
CLOJURE_JLINE_RUNNER=jline.ConsoleRunner
.endif

SUB_LIST+=	CLOJURE_JLINE_RUNNER=${CLOJURE_JLINE_RUNNER}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/clojure-bin ${STAGEDIR}${PREFIX}/bin/clojure
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}/clojure.jar

.include <bsd.port.mk>
