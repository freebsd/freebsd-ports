# Created by: ijliao
# $FreeBSD$

PORTNAME=	clojure
PORTVERSION=	1.5.1
PORTEPOCH=	2
CATEGORIES=	lang lisp java
MASTER_SITES=	http://repo1.maven.org/maven2/org/clojure/clojure/${PORTVERSION}/

MAINTAINER=	jan0sch@gmx.net
COMMENT=	Dynamic programming language for the JVM

LICENSE=	EPL

USES=		zip
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
RUN_DEPENDS+=	jline>=0.9.91:${PORTSDIR}/devel/jline
CLOJURE_JLINE_RUNNER=jline.ConsoleRunner
.endif

SUB_LIST+=	CLOJURE_JLINE_RUNNER=${CLOJURE_JLINE_RUNNER}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/clojure-bin ${STAGEDIR}${PREFIX}/bin/clojure
	@${INSTALL_DATA} ${WRKSRC}/clojure-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/clojure.jar

.include <bsd.port.mk>
