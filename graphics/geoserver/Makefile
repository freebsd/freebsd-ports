# Created by: Wen heping<wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	geoserver
PORTVERSION=	2.16.2
CATEGORIES=	graphics geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open Source GIS server

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GEOSERVERDIR=	${PREFIX}/${PORTNAME}
GEODIRS=	data_dir etc lib logs modules resources webapps

USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	G="${GEOSERVERDIR:S,^${PREFIX}/,,}" VER1=22.2 MVER=${PORTVERSION} \
		VER3=1.1.3 BATIK=1.10 GWC=1.16.2 \
		JETTY=9.4.18.v20190429 IMAGEIO=1.3.2 JT=1.1.12 SPRINGS=5.1.5
SUB_LIST=	GEOSERVERDIR="${GEOSERVERDIR}" JAVA="${JAVA}"
SUB_FILES=	pkg-message
NO_ARCH=	yes

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
	(cd ${WRKSRC} && ${INSTALL_DATA} GPL.txt LICENSE.txt README.txt RUNNING.txt \
		VERSION.txt start.jar ${STAGEDIR}${GEOSERVERDIR})
.for dir in ${GEODIRS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${GEOSERVERDIR})
.endfor

.include <bsd.port.mk>
