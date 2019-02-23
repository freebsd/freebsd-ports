# $FreeBSD$

PORTNAME=	igv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.19
CATEGORIES=	biology java
MASTER_SITES=	http://software.broadinstitute.org/software/igv/sites/cancerinformatics.org.igv/files/images/:img
DISTFILES=	tools.png:img
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization tool for genomic datasets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel \
		gradle4:devel/gradle4
RUN_DEPENDS=	openjfx8-devel>0:java/openjfx8-devel

USES=		gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	igvteam
USE_JAVA=	yes
NO_ARCH=	yes

MAKE_ENV+=	GRADLE_USER_HOME=${WRKDIR}

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="IGV" "Integrative Genomics Viewer" "${PREFIX}/share/pixmaps/igv.xpm" "${PORTNAME}" \
		"Biology;Science;" true

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/batik-codec-1.10.jar \
		${JAVAJARDIR}/goby-io-igv-1.1.jar \
		${JAVAJARDIR}/log4j-core-2.11.0.jar \
		${JAVAJARDIR}/${PORTNAME}.jar \
		share/pixmaps/igv.png

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle4 createDist

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/build/IGV-dist/lib/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/IGV-dist/lib/batik-codec-1.10.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/IGV-dist/lib/goby-io-igv-1.1.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/IGV-dist/lib/log4j-core-2.11.0.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tools.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
