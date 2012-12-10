# Created by: ijliao
# $FreeBSD$

PORTNAME=	clojure
PORTVERSION=	1.4.0
PORTEPOCH=	2
CATEGORIES=	lang lisp java
MASTER_SITES=	http://repo1.maven.org/maven2/org/clojure/clojure/${PORTVERSION}/

MAINTAINER=	jan0sch@gmx.net
COMMENT=	A dynamic programming language for the JVM

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
SUB_FILES=	clojure-bin
OPTIONS=	JLINE "Enable jline support for the REPL" on

PLIST_FILES=	bin/clojure \
		%%JAVAJARDIR%%/clojure.jar

.include <bsd.port.pre.mk>

.ifdef(WITH_JLINE)
RUN_DEPENDS+=	jline>=0.9.91:${PORTSDIR}/devel/jline
CLOJURE_JLINE_RUNNER=jline.ConsoleRunner
.endif

SUB_LIST+=	CLOJURE_JLINE_RUNNER=${CLOJURE_JLINE_RUNNER}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/clojure-bin ${PREFIX}/bin/clojure
	@${INSTALL_DATA} ${WRKSRC}/clojure-${PORTVERSION}.jar ${JAVAJARDIR}/clojure.jar

.include <bsd.port.post.mk>
