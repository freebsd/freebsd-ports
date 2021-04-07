PORTNAME=	opengrok
PORTVERSION=	1.3.16
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/oracle/opengrok/releases/download/${PORTVERSION}/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Fast and powerful code search and cross-reference engine

LICENSE=	CDDL ADAIC BSD3CLAUSE EPL ECMA MIT RUBY
LICENSE_COMB=	multi
LICENSE_FILE_CDDL=	${WRKSRC}/doc/LICENSE.txt
LICENSE_FILE_ADAIC=	${WRKSRC}/doc/LICENSE-adaic.org.txt
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/doc/LICENSE-scala.txt
LICENSE_FILE_EPL=	${WRKSRC}/doc/LICENSE-eclipse.txt
LICENSE_FILE_ECMA=	${WRKSRC}/doc/LICENSE-ecma.txt
LICENSE_FILE_MIT=	${WRKSRC}/doc/LICENSE-mandoc.txt
LICENSE_FILE_RUBY=	${WRKSRC}/doc/LICENSE-ruby.txt
LICENSE_NAME_ADAIC=	Ada Reference Manual, ISO/IEC 8652:2007(E) Ed. 3
LICENSE_PERMS_ADAIC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_ECMA=	Ecma International
LICENSE_PERMS_ECMA=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	uctags:devel/universal-ctags

USE_JAVA=	yes
JAVA_VERSION=	1.8+
SHAREOWN=	www
SHAREGRP=	www
NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	README.md logging.properties.template paths.tsv
SUB_FILES=	opengrok
SUB_LIST+=	LIBFILES="${LIBFILES:S,^,${DATADIR}/lib/,}" \
		JARFILE="${JARFILE}"
PLIST_SUB=	T=${WEBAPP_HOME:S|^${LOCALBASE}/||} \
		OWNER=${SHAREOWN} GROUP=${SHAREGRP}

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		AS
OPTIONS_SINGLE_AS=	GLASSFISH TOMCAT85 TOMCAT9
OPTIONS_DEFAULT=	TOMCAT85

GLASSFISH_DESC?=	Glassfish support

GLASSFISH_VARS=	WEBAPP_HOME=${LOCALBASE}/glassfish-5.1.0/glassfish
TOMCAT85_VARS=	WEBAPP_HOME=${LOCALBASE}/apache-tomcat-8.5
TOMCAT9_VARS=	WEBAPP_HOME=${LOCALBASE}/apache-tomcat-9.0

GLASSFISH_BUILD_DEPENDS=${WEBAPP_HOME}/modules/glassfish.jar:www/glassfish
GLASSFISH_RUN_DEPENDS=	${WEBAPP_HOME}/modules/glassfish.jar:www/glassfish
TOMCAT85_BUILD_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat85
TOMCAT85_RUN_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat85
TOMCAT9_BUILD_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat9
TOMCAT9_RUN_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat9

JARFILE=	${DATADIR}/opengrok.jar
LIBFILES=	activation-1.1.1.jar \
		ant-1.10.1.jar \
		ant-launcher-1.10.1.jar \
		aopalliance-repackaged-2.6.1.jar \
		bcel-6.4.1.jar \
		classmate-1.3.4.jar \
		commons-compress-1.19.jar \
		commons-lang3-3.9.jar \
		cron-utils-7.0.2.jar \
		hibernate-validator-6.0.17.Final.jar \
		hk2-api-2.6.1.jar \
		hk2-locator-2.6.1.jar \
		hk2-utils-2.6.1.jar \
		jackson-annotations-2.10.1.jar \
		jackson-core-2.10.1.jar \
		jackson-databind-2.10.1.jar \
		jackson-module-jaxb-annotations-2.10.1.jar \
		jakarta.activation-api-1.2.1.jar \
		jakarta.annotation-api-1.3.5.jar \
		jakarta.el-3.0.2.jar \
		jakarta.el-api-3.0.3.jar \
		jakarta.inject-2.6.1.jar \
		jakarta.validation-api-2.0.2.jar \
		jakarta.ws.rs-api-2.1.6.jar \
		jakarta.xml.bind-api-2.3.2.jar \
		javassist-3.25.0-GA.jar \
		jaxb-api-2.3.0.jar \
		jaxb-core-2.3.0.jar \
		jaxb-impl-2.3.0.jar \
		jboss-logging-3.3.2.Final.jar \
		jersey-bean-validation-2.30.1.jar \
		jersey-client-2.30.1.jar \
		jersey-common-2.30.1.jar \
		jersey-entity-filtering-2.30.1.jar \
		jersey-hk2-2.30.1.jar \
		jersey-media-jaxb-2.30.1.jar \
		jersey-media-json-jackson-2.30.1.jar \
		jersey-server-2.30.1.jar \
		lucene-analyzers-common-8.5.2.jar \
		lucene-backward-codecs-8.5.2.jar \
		lucene-core-8.5.2.jar \
		lucene-highlighter-8.5.2.jar \
		lucene-join-8.5.2.jar \
		lucene-memory-8.5.2.jar \
		lucene-queries-8.5.2.jar \
		lucene-queryparser-8.5.2.jar \
		lucene-sandbox-8.5.2.jar \
		lucene-suggest-8.5.2.jar \
		opengrok-1.3.16.jar \
		org.suigeneris.jrcs.diff-0.4.2.jar \
		org.suigeneris.jrcs.rcs-0.4.2.jar \
		osgi-resource-locator-1.0.3.jar \
		slf4j-api-1.7.12.jar

WEBAPPS_DIR=	${WEBAPP_HOME:S|^${LOCALBASE}/||}/webapps

post-extract:
	@${MKDIR} ${WRKSRC}/lib/opengrok
	@${TAR} -xf ${WRKSRC}/lib/source.war -C ${WRKSRC}/lib/opengrok

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/etc ${STAGEDIR}${DATADIR}/lib \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME} \
		${STAGEDIR}/var/log/opengrok
	(cd ${WRKSRC}/lib/opengrok && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF && \
		${MV} web.xml web.xml.sample)
	${INSTALL_DATA} ${LIBFILES:S,^,${WRKSRC}/lib/lib/,} \
		${STAGEDIR}${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/opengrok.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/source.war ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/logging.properties ${STAGEDIR}${DATADIR}/etc/logging.properties.sample
	${INSTALL_SCRIPT} ${WRKDIR}/opengrok ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
