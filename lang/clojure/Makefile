# ex:ts=8
# Ports collection makefile for:	clojure
# Date created:			Oct 21. 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clojure
PORTVERSION=	20080612
CATEGORIES=	lang lisp java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dynamic programming language for the JVM

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SUB_FILES=	clojure

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/clojure ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/clojure.jar ${JAVAJARDIR}
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/src/boot.clj ${DATADIR}

.include <bsd.port.mk>
