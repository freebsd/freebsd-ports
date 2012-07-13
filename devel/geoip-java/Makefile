# New ports collection makefile for:	geoip-java
# Date created:		2012-07-12
# Whom:		Jason Helfman <jgh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geoip
PORTVERSION=	1.2.8
CATEGORIES=	devel java
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/java/
DISTNAME=	GeoIPJava-${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Java bindings for GeoIP API

LICENSE=	LGPL21

RUN_DEPENDS=	GeoIP>=1.4.8:${PORTSDIR}/net/GeoIP

PKGNAMESUFFIX:=	-java
USE_ZIP=	YES

USE_JAVA=	YES
JAVA_VERSION=	1.5+
USE_ANT=	YES
ALL_TARGET=	jar

PLIST_FILES=	%%JAVAJARDIR%%/maxmind-geoip-${PORTVERSION}.jar
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

pre-build:
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}

post-build-script:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && \
		${ANT} javadoc
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/maxmind-geoip.jar ${JAVAJARDIR}/maxmind-geoip-${PORTVERSION}.jar
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/javadoc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
