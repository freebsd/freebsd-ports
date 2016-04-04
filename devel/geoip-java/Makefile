# $FreeBSD$

PORTNAME=	geoip
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/java/
DISTNAME=	GeoIPJava-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java bindings for GeoIP API

LICENSE=	LGPL21

RUN_DEPENDS=	GeoIP>=1.4.8:net/GeoIP

PKGNAMESUFFIX:=	-java
USES=		zip

USE_JAVA=	YES
JAVA_VERSION=	1.6+
USE_ANT=	YES
ALL_TARGET=	jar

PLIST_FILES=	%%JAVAJARDIR%%/maxmind-geoip-${PORTVERSION}.jar
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-build:
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}

post-build-script:
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && \
		${ANT} javadoc
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/maxmind-geoip.jar \
		${STAGEDIR}${JAVAJARDIR}/maxmind-geoip-${PORTVERSION}.jar
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/javadoc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
