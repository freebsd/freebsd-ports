# New ports collection makefile for:	geoserver
# Date created:				10 March 2008
# Whom:					Wen heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geoserver
PORTVERSION=	1.7.4
CATEGORIES=	graphics geography java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open Source GIS Server

USE_JAVA=	yes
USE_ZIP=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GEOSERVERDIR=	${PREFIX}/${PORTNAME}
GEODIRS=	data_dir etc lib logs resources webapps

USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	G="${GEOSERVERDIR:S,^${PREFIX}/,,}"
SUB_LIST=	GEOSERVERDIR="${GEOSERVERDIR}" JAVA="${JAVA}"
SUB_FILES=	pkg-message

post-patch:
	@${RM} ${WRKSRC}/webapps/geoserver/editarea/images/Thumbs.db
	@${REINPLACE_CMD} -e 's|$$GEOSERVER_HOME|${GEOSERVERDIR}|g' \
		-e 's|%%JAVA%%|${JAVA}|g' \
		${WRKSRC}/bin/startup.sh ${WRKSRC}/bin/shutdown.sh

do-install:
	@${MKDIR} ${GEOSERVERDIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${GEOSERVERDIR}/bin
.for f in GPL.txt LICENSE.txt README.txt RUNNING.txt start.jar
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
