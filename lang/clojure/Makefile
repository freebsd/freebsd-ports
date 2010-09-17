# ex:ts=8
# Ports collection makefile for:	clojure
# Date created:			Oct 21. 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clojure
PORTVERSION=	1.2.0
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	lang lisp java
MASTER_SITES=	http://cloud.github.com/downloads/clojure/clojure/

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	A dynamic programming language for the JVM

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
SUB_FILES=	clojure-bin
OPTIONS=	JLINE "Enable jline support for the REPL" on

PLIST_FILES=	bin/clojure \
		%%JAVAJARDIR%%/clojure-1.2.0.jar

.include <bsd.port.pre.mk>

.ifdef(WITH_JLINE)
RUN_DEPENDS+=	jline>=0.9.91:${PORTSDIR}/devel/jline
CLOJURE_JLINE_RUNNER=jline.ConsoleRunner
.endif

SUB_LIST+=	CLOJURE_JLINE_RUNNER=${CLOJURE_JLINE_RUNNER}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/clojure-bin ${PREFIX}/bin/clojure
	@${INSTALL_DATA} ${WRKSRC}/clojure.jar ${JAVAJARDIR}/clojure-1.2.0.jar

.include <bsd.port.post.mk>
