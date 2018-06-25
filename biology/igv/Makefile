# $FreeBSD$

PORTNAME=	igv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.10
CATEGORIES=	biology java
MASTER_SITES=	http://www.broadinstitute.org/software/igv/sites/cancerinformatics.org.igv/files/images/:img
DISTFILES=	tools.png:img
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization tool for genomic datasets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel
RUN_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel

USES=		gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	igvteam
USE_JAVA=	yes
USE_ANT=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="IGV" "Integrative Genomics Viewer" "${PREFIX}/share/pixmaps/igv.xpm" "${PORTNAME}" \
		"Biology;Science;" true

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/batik-codec__V1.7.jar \
		${JAVAJARDIR}/goby-io-igv__V1.0.jar \
		${JAVAJARDIR}/${PORTNAME}.jar \
		share/pixmaps/igv.png

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/batik-codec__V1.7.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/goby-io-igv__V1.0.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tools.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
