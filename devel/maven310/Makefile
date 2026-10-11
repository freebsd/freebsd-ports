PORTNAME=	maven
DISTVERSION=	3.10.0
CATEGORIES=	devel java
MASTER_SITES=	APACHE/maven/maven-3/${DISTVERSION}/binaries
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}
.endif
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	michaelo@apache.org
COMMENT=	Java project management tool
WWW=		https://maven.apache.org/

LICENSE=	APACHE20

EXTRACT_DEPENDS=	zip:archivers/zip
RUN_DEPENDS=		mvn:devel/maven-wrapper

USES=		cpe java
CPE_VENDOR=	apache
CPE_PRODUCT=	maven

DATADIR=	${JAVASHAREDIR}/${INSTANCE_ID}
NO_ARCH=	yes
NO_ARCH_IGNORE=	libjlinenative.so
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin//}
PLIST_SUB=	INSTANCE_ID=${INSTANCE_ID} \
		INSTANCES_DIR=${INSTANCES_DIR} \
		PORTVERSION=${PORTVERSION}
INSTANCE_ID=	${DISTNAME:S/-bin//:R}
INSTANCES_DIR=	${LOCALBASE}/etc/maven-wrapper/instances.d

ZIP_CMD?=	${LOCALBASE}/bin/zip

post-extract:
	${RM} ${WRKSRC}/bin/*.cmd
	${RM} -r ${WRKSRC}/lib/jline-native/Linux ${WRKSRC}/lib/jline-native/Windows
	${FIND} ${WRKSRC}/lib -type f -name jline-native-*.jar \
		-exec ${ZIP_CMD} -dq {} org/jline/nativ/Linux/\* \
			org/jline/nativ/Mac/\* org/jline/nativ/Windows/\* \
			org/jline/nativ/FreeBSD/\* \;

post-patch:
	@${REINPLACE_CMD} \
		-e '37,40d;78,96d;99,100d' \
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
	${ECHO_CMD} "${DATADIR}" > ${WRKDIR}/${INSTANCE_ID}
	${INSTALL_DATA} ${WRKDIR}/${INSTANCE_ID} \
		${STAGEDIR}${INSTANCES_DIR}

.include <bsd.port.mk>
