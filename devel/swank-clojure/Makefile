# Ports collection makefile for:	swank-clojure
# Date created:		Jun 17 2010
# Whom:			olgeni
#
# $FreeBSD$
#

PORTNAME=	swank-clojure
PORTVERSION=	1.1.0
CATEGORIES=	devel lisp java
MASTER_SITES=	http://repo.technomancy.us/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Swank/SLIME support for Clojure

USE_JAVA=	yes
JAVA_VERSION=	1.5+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%JAVAJARDIR%%/swank-clojure.jar

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVAJARDIR}/swank-clojure.jar

.include <bsd.port.mk>
