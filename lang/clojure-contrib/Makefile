# ex:ts=8
# Ports collection makefile for:	clojure-contrib
# Date created:		Jun 12 2010
# Whom:			olgeni
#
# $FreeBSD$
#

PORTNAME=	clojure-contrib
PORTVERSION=	1.1.0
CATEGORIES=	lang lisp java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Extensions and enhancements to the Clojure libraries

BUILD_DEPENDS=	${LOCALBASE}/bin/clojure:${PORTSDIR}/lang/clojure

USE_ZIP=	yes
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

MAKE_ARGS+=	-Dclojure.jar=${JAVAJARDIR}/clojure.jar

do-install:
	@${INSTALL_DATA} ${WRKSRC}/clojure-contrib.jar ${JAVAJARDIR}/clojure-contrib.jar

.include <bsd.port.mk>
