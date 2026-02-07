PORTNAME=	opengrok
DISTVERSION=	1.14.1
CATEGORIES=	devel java
# Doesn't currently work with portscout, but the release tarball is required.
MASTER_SITES=	https://github.com/oracle/opengrok/releases/download/${PORTVERSION}/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Fast and powerful code search and cross-reference engine
WWW=		https://opengrok.github.io/OpenGrok/

LICENSE=	CDDL ADAIC BSD3CLAUSE EPL ECMA MIT RUBY
LICENSE_COMB=	multi
LICENSE_NAME_ADAIC=	Ada Reference Manual, ISO/IEC 8652:2007(E) Ed. 3
LICENSE_NAME_ECMA=	Ecma International
LICENSE_FILE_CDDL=	${WRKSRC}/doc/LICENSE.txt
LICENSE_FILE_ADAIC=	${WRKSRC}/doc/LICENSE-adaic.org.txt
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/doc/LICENSE-scala.txt
LICENSE_FILE_EPL=	${WRKSRC}/doc/LICENSE-eclipse.txt
LICENSE_FILE_ECMA=	${WRKSRC}/doc/LICENSE-ecma.txt
LICENSE_FILE_MIT=	${WRKSRC}/doc/LICENSE-mandoc.txt
LICENSE_FILE_RUBY=	${WRKSRC}/doc/LICENSE-ruby.txt
LICENSE_PERMS_ADAIC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ECMA=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	uctags:devel/universal-ctags

USES=		cpe java
CPE_VENDOR=	oracle
JAVA_VERSION=	17+
SHAREOWN=	www
SHAREGRP=	www
NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	README.md logging.properties.template
SUB_FILES=	opengrok pkg-message
SUB_LIST+=	JARFILE="${JARFILE}"
PLIST_SUB=	T=${WEBAPP_HOME:S|^${LOCALBASE}/||} \
		OWNER=${SHAREOWN} GROUP=${SHAREGRP}

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		AS
OPTIONS_SINGLE_AS=	GLASSFISH TOMCAT101
OPTIONS_DEFAULT=	TOMCAT101

GLASSFISH_DESC=		Glassfish support

GLASSFISH_VARS=	WEBAPP_HOME=${LOCALBASE}/glassfish-5.1.0/glassfish
TOMCAT101_VARS=	WEBAPP_HOME=${LOCALBASE}/apache-tomcat-10.1

GLASSFISH_BUILD_DEPENDS=${WEBAPP_HOME}/modules/glassfish.jar:www/glassfish
GLASSFISH_RUN_DEPENDS=	${WEBAPP_HOME}/modules/glassfish.jar:www/glassfish
TOMCAT101_BUILD_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat101
TOMCAT101_RUN_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat101

WEBAPPS_DIR=	${WEBAPP_HOME:S|^${LOCALBASE}/||}/webapps
JARFILE=	${LOCALBASE}/${WEBAPPS_DIR}/opengrok/WEB-INF/lib/opengrok-${PORTVERSION}.jar

post-extract:
	@${MKDIR} ${WRKSRC}/lib/opengrok
	@${TAR} -xf ${WRKSRC}/lib/source.war -C ${WRKSRC}/lib/opengrok
	@${RM} ${WRKSRC}/lib/opengrok/WEB-INF/classes/sample.c # clean cruft

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/etc \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME} \
		${STAGEDIR}/var/log/opengrok
	(cd ${WRKSRC}/lib/opengrok && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF && \
		${MV} web.xml web.xml.sample)
	${INSTALL_DATA} ${WRKSRC}/doc/logging.properties ${STAGEDIR}${DATADIR}/etc/logging.properties.sample
	${INSTALL_SCRIPT} ${WRKDIR}/opengrok ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
