PORTNAME=	geoserver
DISTVERSION=	2.28.1
CATEGORIES=	graphics geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Open Source GIS server
WWW=		https://geoserver.org/

LICENSE=	APACHE20 BSD2CLAUSE EPL GPLv2 GPLv3 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/license/NOTICE.txt

USES=		cpe java zip
JAVA_VERSION=	17+
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	GEOSERVERDIR="${GEOSERVERDIR}" \
		JAVA="${JAVA}"

NO_WRKSUBDIR=	yes

GEOSERVERDIR=	${PREFIX}/${PORTNAME}
GEODIRS=	data_dir etc lib logs modules resources webapps

PLIST_SUB=	BATIK=1.18 \
		ECLIPSE=2.15.0 \
		G="${GEOSERVERDIR:S,^${PREFIX}/,,}" \
		GT=34.1 \
		GWC=1.28.1 \
		IMAGEIO=2.0.1 \
		JACKSON=2.19.0 \
		JETTY=10.0.25 \
		JNA=5.17.0 \
		JT=0.9.1 \
		MVER=${PORTVERSION} \
		SI=2.2 \
		SPRING=5.3.39 \
		SPRINGS=5.8.16 \
		WICKET=9.21.0

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
