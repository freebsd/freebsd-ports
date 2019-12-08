# Created by: JonathanChen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	maven
DISTVERSION=	3.6.3
CATEGORIES=	devel java
MASTER_SITES=	APACHE/maven/maven-3/${DISTVERSION}/binaries
DISTNAME=	apache-maven-${DISTVERSION}-bin

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Java project management tool

LICENSE=	APACHE20

RUN_DEPENDS=	mvn:devel/maven-wrapper

USES=		cpe
USE_JAVA=	yes

CPE_PRODUCT=	maven
CPE_VENDOR=	apache
NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/apache-maven-${DISTVERSION}
SUB_FILES=	mvn.sh
SUB_LIST=	CLASSWORLDS_JAR=plexus-classworlds-2.6.0.jar
PLIST_SUB=	PORTVERSION=${PORTVERSION}
INSTANCE_FILE=	${PORTNAME}-${PORTVERSION}
INSTANCES_DIR=	etc/maven-wrapper/instances.d/

post-extract:
	${RM} -r ${WRKSRC}/lib/jansi-native ${WRKSRC}/bin/*.bat
	${ECHO_CMD} "${DATADIR}" > ${WRKSRC}/${INSTANCE_FILE}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} \
		${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -not -path "\./bin/" \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/bin/m2.conf ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/mvn.sh ${STAGEDIR}${DATADIR}/bin/mvn
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INSTANCES_DIR}
	${INSTALL_DATA} ${WRKSRC}/${INSTANCE_FILE} \
		${STAGEDIR}${PREFIX}/${INSTANCES_DIR}

.include <bsd.port.mk>
