# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maven2
DISTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	maven/binaries
DISTNAME=	apache-maven-${DISTVERSION}-bin

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java project management tool, 2.0 branch

RUN_DEPENDS=	mvn:${PORTSDIR}/devel/maven-wrapper

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	m2.sh
SUB_LIST=	CLASSWORLDS_JAR=classworlds-1.1.jar
WRKSRC=		${WRKDIR}/apache-maven-${DISTVERSION}
INSTANCE_FILE=	020201-${PORTNAME}-${PORTVERSION}
INSTANCES_DIR=	etc/maven-wrapper/instances.d/
PLIST_FILES=	${INSTANCES_DIR}/${INSTANCE_FILE}

NO_STAGE=	yes
post-extract:
	${RM} -f ${WRKSRC}/bin/m2.bat
	${ECHO_CMD} "${DATADIR}" > ${WRKSRC}/${INSTANCE_FILE}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -not -path "\./bin/" -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/bin/m2.conf ${DATADIR}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/m2.sh ${DATADIR}/bin/mvn
	${MKDIR} ${PREFIX}/${INSTANCES_DIR}
	${INSTALL_DATA} ${WRKSRC}/${INSTANCE_FILE} ${PREFIX}/${INSTANCES_DIR}

post-install:
	@${FIND} -s ${WRKSRC} -not -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}

.include <bsd.port.mk>
