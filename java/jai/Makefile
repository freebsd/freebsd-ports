# Created by: OISHI Masakuni <yamasa@bsdhouse.org>

PORTNAME=	jai
DISTVERSION=	1_1_3
PORTREVISION=	2
CATEGORIES=	java graphics
MASTER_SITES=	http://download.java.net/media/${PORTNAME}/builds/release/${PORTVERSION:S/./_/g}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-lib

MAINTAINER=	java@FreeBSD.org
COMMENT=	High performance image processing libraries for Java

# Converted from RESTRICTED
LICENSE=	jai
LICENSE_NAME=	jai
LICENSE_TEXT=	Redistribution is not permitted
LICENSE_PERMS=	auto-accept

USES=		cpe zip
CPE_VENDOR=	oracle
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	TARGET_DIR=${TARGET_DIR}

DOWNLOAD_URL=	http://java.sun.com/products/java-media/jai/current.html

TARGET_DIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}

PORTDOCS=	\
		COPYRIGHT-jai.txt \
		DISTRIBUTIONREADME-jai.txt \
		LICENSE-jai.txt \
		THIRDPARTYLICENSEREADME-jai.txt

OPTIONS_DEFINE=	DOCS

do-install:
# documentation
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
# jars
	@${MKDIR} ${STAGEDIR}${TARGET_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/jai_codec.jar ${STAGEDIR}${TARGET_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/jai_core.jar ${STAGEDIR}${TARGET_DIR}

.include <bsd.port.mk>
