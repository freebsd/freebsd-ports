# Created by: arved
# $FreeBSD$

PORTNAME=	rjb
PORTVERSION=	1.5.3
CATEGORIES=	java ruby
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Call Java Code from Ruby

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE=		fails to create JVM
DEPRECATED=	fails to create JVM
EXPIRATION_DATE=2016-06-02

USE_RUBY=	yes
USES=		gem
USE_JAVA=	yes
GEM_ENV=	JAVA_HOME=${JAVA_HOME}

.include <bsd.port.mk>
