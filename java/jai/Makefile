# New ports collection makefile for:	JAI
# Date created:				2004-01-10
# Whom:					OISHI Masakuni <yamasa@bsdhouse.org>
#
# $FreeBSD$
#

PORTNAME=	jai
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	java graphics
MASTER_SITES=	#
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-lib

MAINTAINER=	java@FreeBSD.org
COMMENT=	High performance image processing libraries for Java

USE_JAVA=	yes
JAVA_VERSION=	1.3+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./_/g}
NO_BUILD=	yes

USE_ZIP=	yes
SUB_FILES=	pkg-message
SUB_LIST=	TARGET_DIR=${TARGET_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

RESTRICTED=	"Redistribution is not permitted"

DOWNLOAD_URL=	http://java.sun.com/products/java-media/jai/current.html

TARGET_DIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}

PORTDOCS=	\
		COPYRIGHT-jai.txt \
		DISTRIBUTIONREADME-jai.txt \
		LICENSE-jai.txt \
		THIRDPARTYLICENSEREADME-jai.txt

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		"You must manually fetch from the \"Java Advanced Imaging API 1.1.3 Download Page\", the \"Java (no native acceleration)\" distribution \(${DISTNAME}${EXTRACT_SUFX}\) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again"
.endif

do-install:
# documentation
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
# jars
	@${MKDIR} ${TARGET_DIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/jai_codec.jar ${TARGET_DIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/jai_core.jar ${TARGET_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
