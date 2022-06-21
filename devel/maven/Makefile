PORTNAME=	maven
DISTVERSION=	3.8.6
CATEGORIES=	devel java
MASTER_SITES=	APACHE/maven/maven-3/${DISTVERSION}/binaries
DISTNAME=	apache-maven-${DISTVERSION}-bin

MAINTAINER=	michaelo@apache.org
COMMENT=	Java project management tool

LICENSE=	APACHE20

RUN_DEPENDS=	mvn:devel/maven-wrapper

USES=		cpe
CPE_VENDOR=	apache
CPE_PRODUCT=	maven
USE_JAVA=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/apache-maven-${DISTVERSION}
PLIST_SUB=	PORTVERSION=${PORTVERSION}
INSTANCE_FILE=	${PORTNAME}-${PORTVERSION}
INSTANCES_DIR=	etc/maven-wrapper/instances.d/

post-extract:
	${RM} -r ${WRKSRC}/lib/jansi-native ${WRKSRC}/bin/*.cmd
	${ECHO_CMD} "${DATADIR}" > ${WRKSRC}/${INSTANCE_FILE}

post-patch:
	@${REINPLACE_CMD} \
		-e '54,72d;74,75d' \
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INSTANCES_DIR}
	${INSTALL_DATA} ${WRKSRC}/${INSTANCE_FILE} \
		${STAGEDIR}${PREFIX}/${INSTANCES_DIR}

.include <bsd.port.mk>
