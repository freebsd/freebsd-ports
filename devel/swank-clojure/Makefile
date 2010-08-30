# Ports collection makefile for:	swank-clojure
# Date created:		Jun 17 2010
# Whom:			olgeni
#
# $FreeBSD$
#

PORTNAME=	swank-clojure
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel lisp java
MASTER_SITES=	http://download.github.com/
DISTNAME=	technomancy-${PORTNAME}-${PORTVERSION}-0-ga0c9a2c

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Swank/SLIME support for Clojure

USE_JAVA=	yes
JAVA_VERSION=	1.5+

WRKSRC=		${WRKDIR}/technomancy-swank-clojure-a0c9a2c

PLIST_FILES=	%%JAVAJARDIR%%/swank-clojure-1.2.0.jar

do-build:
	@cd ${WRKSRC} && ${JAR} cf ${PORTNAME}-${PORTVERSION}.jar -C src swank

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}

.include <bsd.port.mk>
