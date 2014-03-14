# Created by: Wen heping<wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	geoserver
PORTVERSION=	2.1.1
CATEGORIES=	graphics geography java
MASTER_SITES=	SF/${PORTNAME}/GeoServer/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Open Source GIS Server

LICENSE=	GPLv2

USE_JAVA=	yes
USES=		zip
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GEOSERVERDIR=	${PREFIX}/${PORTNAME}
GEODIRS=	data_dir etc lib logs resources webapps

USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	G="${GEOSERVERDIR:S,^${PREFIX}/,,}" GTVER=2.7.2 MVER=${PORTVERSION}
SUB_LIST=	GEOSERVERDIR="${GEOSERVERDIR}" JAVA="${JAVA}"
SUB_FILES=	pkg-message

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$$GEOSERVER_HOME|${GEOSERVERDIR}|g' \
		-e 's|%%JAVA%%|${JAVA}|g' \
		${WRKSRC}/bin/startup.sh ${WRKSRC}/bin/shutdown.sh

do-install:
	@${MKDIR} ${GEOSERVERDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${GEOSERVERDIR}/bin
.for f in LICENSE.txt README.txt RUNNING.txt VERSION.txt start.jar
	${INSTALL_DATA} ${WRKSRC}/${f} ${GEOSERVERDIR}
.endfor
.for dir in ${GEODIRS}
	@(cd ${WRKSRC};${FIND} -E ${dir} -type f -iregex ".*(keystore|\.(xml|properties))") \
		| while read a; do \
			${MV} ${WRKSRC}/$$a ${WRKSRC}/$$a.sample; \
			if [ ! -e "${GEOSERVERDIR}/$$a" ]; then \
				${CP} ${WRKSRC}/$$a.sample ${WRKSRC}/$$a; \
			fi; \
		done
	@cd ${WRKSRC} && \
		${FIND} ${dir} -type d -exec \
			${MKDIR} "${GEOSERVERDIR}/{}" \; && \
		${FIND} ${dir} -type f -exec \
			${INSTALL_DATA} "${WRKSRC}/{}" "${GEOSERVERDIR}/{}" \;
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
