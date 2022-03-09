# Created by: Wen heping<wenheping@gmail.com>

PORTNAME=	geoserver
PORTVERSION=	2.20.3
CATEGORIES=	graphics geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open Source GIS server

LICENSE=	APACHE20 BSD2CLAUSE EPL GPLv2 GPLv3 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/NOTICE.md

USES=		cpe zip
USE_JAVA=	yes
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	GEOSERVERDIR="${GEOSERVERDIR}" \
		JAVA="${JAVA}"

NO_WRKSUBDIR=	yes

GEOSERVERDIR=	${PREFIX}/${PORTNAME}
GEODIRS=	data_dir etc lib logs modules resources webapps

PLIST_SUB=	BATIK=1.14 \
		ECLIPSE=2.15.0 \
		G="${GEOSERVERDIR:S,^${PREFIX}/,,}" \
		GWC=1.20.1 \
		IMAGEIO=1.3.10 \
		JETTY=9.4.36.v20210114 \
		JT1=1.6.0 \
		JT=1.1.21 \
		MVER=${PORTVERSION} \
		SI=2.0.1 \
		SPRING=5.1.20 \
		SPRINGS=5.1.13 \
		VER1=26.3 \
		VER3=1.1.3 \
		WICKET=7.18.0

post-patch:
	@${REINPLACE_CMD} -e 's|$$GEOSERVER_HOME|${GEOSERVERDIR}|g' \
		-e 's|%%JAVA%%|${JAVA}|g' \
		${WRKSRC}/bin/startup.sh ${WRKSRC}/bin/shutdown.sh
	@(cd ${WRKSRC}/etc;${FIND} -E . -type f -iregex ".*(keystore|\.(xml|properties))") \
		| while read a; do \
			${MV} ${WRKSRC}/etc/$$a ${WRKSRC}/etc/$$a.sample; \
		done

do-install:
	@${MKDIR} ${STAGEDIR}${GEOSERVERDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${STAGEDIR}${GEOSERVERDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/start.jar ${STAGEDIR}${GEOSERVERDIR}/
	${INSTALL_DATA} ${WRKSRC}/start.ini ${STAGEDIR}${GEOSERVERDIR}/
	(cd ${WRKSRC} && ${INSTALL_DATA} NOTICE.md README.txt RUNNING.txt license/* \
		VERSION.txt start.jar ${STAGEDIR}${GEOSERVERDIR})
.for dir in ${GEODIRS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${GEOSERVERDIR})
.endfor

.include <bsd.port.mk>
