PORTNAME=	geoserver
DISTVERSION=	2.25.3
CATEGORIES=	graphics geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open Source GIS server
WWW=		https://geoserver.org/

LICENSE=	APACHE20 BSD2CLAUSE EPL GPLv2 GPLv3 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/license/NOTICE.txt

USES=		cpe zip
USE_JAVA=	17+
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	GEOSERVERDIR="${GEOSERVERDIR}" \
		JAVA="${JAVA}"

NO_WRKSUBDIR=	yes

GEOSERVERDIR=	${PREFIX}/${PORTNAME}
GEODIRS=	data_dir etc lib logs modules resources webapps

PLIST_SUB=	BATIK=1.17 \
		ECLIPSE=2.15.0 \
		G="${GEOSERVERDIR:S,^${PREFIX}/,,}" \
		GT=31.3 \
		GWC=1.25-SNAPSHOT \
		IMAGEIO=1.4.12 \
		JETTY=9.4.52.v20230823 \
		JNA=5.14.0 \
		JT=1.1.25 \
		JT1=1.6.0 \
		MVER=${PORTVERSION} \
		SI=2.1 \
		SPRING=5.3.34 \
		SPRINGS=5.7.12 \
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
	(cd ${WRKSRC} && ${INSTALL_DATA} README.html RUNNING.html license/* \
		VERSION.txt start.jar ${STAGEDIR}${GEOSERVERDIR})
.for dir in ${GEODIRS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${GEOSERVERDIR})
.endfor

.include <bsd.port.mk>
