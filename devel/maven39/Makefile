PORTNAME=	maven
DISTVERSION=	3.9.11
CATEGORIES=	devel java
MASTER_SITES=	APACHE/maven/maven-3/${DISTVERSION}/binaries
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	michaelo@apache.org
COMMENT=	Java project management tool
WWW=		https://maven.apache.org/

LICENSE=	APACHE20

RUN_DEPENDS=	mvn:devel/maven-wrapper

USES=		cpe java
CPE_VENDOR=	apache
CPE_PRODUCT=	maven

DATADIR=	${JAVASHAREDIR}/${INSTANCE_ID}
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin//}
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
	INSTANCE_ID=${INSTANCE_ID} \
	INSTANCES_DIR=${INSTANCES_DIR}
INSTANCE_ID=	${DISTNAME:S/-bin//:R}
INSTANCES_DIR=	${LOCALBASE}/etc/maven-wrapper/instances.d

post-extract:
	${RM} -r ${WRKSRC}/lib/jansi-native ${WRKSRC}/bin/*.cmd
	${ECHO_CMD} "${DATADIR}" > ${WRKDIR}/${INSTANCE_ID}

post-patch:
	@${REINPLACE_CMD} \
		-e '37,40d;55,73d;76,77d' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-E -e 's|^MAVEN_HOME=.+$$|MAVEN_HOME="${DATADIR}"|g' ${WRKSRC}/bin/mvn
	@${FIND} ${WRKSRC} -name '*.bak' -delete -o -name '*.orig' -delete

do-install:
	@cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} \
		${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -not -path "\./bin/" \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	@cd ${STAGEDIR}${DATADIR} && ${FIND} conf -type f -exec ${CP} \
		'{}' '{}'.sample \;
	${INSTALL_DATA} ${WRKSRC}/bin/m2.conf ${STAGEDIR}${DATADIR}/bin/m2.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mvn ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mvnDebug ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mvnyjp ${STAGEDIR}${DATADIR}/bin
	@${MKDIR} ${STAGEDIR}${INSTANCES_DIR}
	${INSTALL_DATA} ${WRKDIR}/${INSTANCE_ID} \
		${STAGEDIR}${INSTANCES_DIR}

.include <bsd.port.mk>
