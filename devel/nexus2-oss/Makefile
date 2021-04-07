PORTNAME=	nexus2
PORTVERSION=	2.14.18
DISTVERSIONSUFFIX=	01
CATEGORIES=	devel www java
MASTER_SITES=	https://download.sonatype.com/nexus/oss/
PKGNAMESUFFIX=	-oss
DISTNAME=	nexus-${PORTVERSION}-${DISTVERSIONSUFFIX}-bundle

MAINTAINER=	michael.osipov@siemens.com
COMMENT=	Maven (and others) artifacts repository manager

LICENSE=	EPL

PATCH_DEPENDS=	zip:archivers/zip
RUN_DEPENDS=	javaservicewrapper:sysutils/javaservicewrapper

USES=		cpe

CPE_VENDOR=	sonatype

NO_ARCH=	yes
NO_BUILD=	yes
NO_TEST=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.8+

USE_RC_SUBR=	${PORTNAME}

NEXUS_USER=	nexus
NEXUS_GROUP=	nexus
USERS=		${NEXUS_USER}
GROUPS=		${NEXUS_GROUP}

# Change to Java rules
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/nexus-${RELEASEVERSION}

WRAPPER_DIR=	${PREFIX}/lib/javaservicewrapper
WRAPPER_CMD=	${WRAPPER_DIR}/bin/wrapper
WRAPPER_LIBDIR=	${WRAPPER_DIR}/lib
WRAPPER_JAR=	${WRAPPER_LIBDIR}/wrapper.jar

NEXUS_RUNDIR=	/var/run/${PORTNAME}
NEXUS_LOGDIR=	/var/log/${PORTNAME}
NEXUS_WORKDIR=	/var/${PORTNAME}

ZIP_CMD?=	${LOCALBASE}/bin/zip

RELEASEVERSION=	${PORTVERSION}-${DISTVERSIONSUFFIX}

NEXUS_CORE_JAR=	${WRKSRC}/nexus/WEB-INF/lib/nexus-core-${RELEASEVERSION}.jar

SUB_FILES=	pkg-message
SUB_LIST=	NEXUS_RC=${PORTNAME} \
		DESC="${COMMENT}" \
		VERSION=${PORTVERSION} \
		BOOKVERSION=${PORTVERSION:C/..$//1} \
		USER=${NEXUS_USER} \
		GROUP=${NEXUS_GROUP} \
		WRAPPER_CMD=${WRAPPER_CMD} \
		RUNDIR=${NEXUS_RUNDIR} \
		LOGDIR=${NEXUS_LOGDIR} \
		WORKDIR=${NEXUS_WORKDIR}
PLIST_SUB=	USER=${NEXUS_USER} \
		GROUP=${NEXUS_GROUP} \
		RUNDIR=${NEXUS_RUNDIR} \
		LOGDIR=${NEXUS_LOGDIR} \
		WORKDIR=${NEXUS_WORKDIR} \
		VERSION=${RELEASEVERSION}

# PATCH NOTES
#   Several patches are necessary due to the following issues:
#   * https://issues.sonatype.org/browse/NEXUS-10981
#   * https://issues.sonatype.org/browse/NEXUS-10983
#   * https://issues.sonatype.org/browse/NEXUS-10984

post-extract:
	@${MV} ${WRKSRC}/bin/jsw/conf/wrapper.conf ${WRKSRC}/conf
.for dir in bin logs tmp
	@${RM} -rd ${WRKSRC}/${dir}
.endfor

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|%%ETCDIR%%|${ETCDIR}|g' \
		-e 's|%%JAVA%%|${JAVA}|g' \
		-e 's|%%LOGDIR%%|${NEXUS_LOGDIR}|g' \
		-e 's|%%WORKDIR%%|${NEXUS_WORKDIR}|g' \
		-e 's|%%WRAPPER_JAR%%|${WRAPPER_JAR}|g' \
		-e 's|%%WRAPPER_LIBDIR%%|${WRAPPER_LIBDIR}|g' \
		${WRKSRC}/conf/nexus.properties ${WRKSRC}/conf/wrapper.conf
	@${FIND} ${WRKSRC} -name '*.bak' -delete -o -name '*.orig' -delete
	@(cd ${FILESDIR}/nexus/WEB-INF/lib/nexus-core.jar \
		&& ${ZIP_CMD} -rq ${NEXUS_CORE_JAR} META-INF)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@(cd ${STAGEDIR}${DATADIR} && ${MV} conf ${STAGEDIR}${ETCDIR})
	@(cd ${STAGEDIR}${ETCDIR} \
		&& ${FIND} . -type f -exec ${MV} '{}' '{}'.sample \;)
	@${MKDIR} ${STAGEDIR}${NEXUS_RUNDIR}
	@${MKDIR} ${STAGEDIR}${NEXUS_LOGDIR}
	@${MKDIR} ${STAGEDIR}${NEXUS_WORKDIR}

.include <bsd.port.mk>
