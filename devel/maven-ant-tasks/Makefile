# $FreeBSD$

PORTNAME=	maven-ant-tasks
PORTVERSION=	2.1.3
CATEGORIES=	devel java
MASTER_SITES=	APACHE/maven/binaries
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Allows Maven artifact handling to be used from within an Ant build

LICENSE=	APACHE20

RUN_DEPENDS=	ant:devel/apache-ant

USE_JAVA=	1.6+

NO_BUILD=	yes
PLIST_FILES=	%%JAVASHAREDIR%%/apache-ant/lib/${DISTNAME}${EXTRACT_SUFX}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/apache-ant/lib
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVASHAREDIR}/apache-ant/lib

.include <bsd.port.mk>
