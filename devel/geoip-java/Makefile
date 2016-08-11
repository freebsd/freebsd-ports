# $FreeBSD$

PORTNAME=	geoip
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/java/
PKGNAMESUFFIX=	-java
DISTNAME=	GeoIPJava-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java bindings for GeoIP API

LICENSE=	LGPL20+ # source sayas LGPL20+, LICENSE saya LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	GeoIP>=1.4.8:net/GeoIP

USES=		zip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	jar
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

PLIST_FILES=	%%JAVAJARDIR%%/maxmind-geoip-${PORTVERSION}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-build:
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}

post-build-DOCS-on:
	cd ${WRKSRC} && ${ANT} javadoc

do-install:
	${INSTALL_DATA} ${WRKSRC}/maxmind-geoip.jar \
		${STAGEDIR}${JAVAJARDIR}/maxmind-geoip-${PORTVERSION}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/javadoc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
