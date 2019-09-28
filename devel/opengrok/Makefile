# $FreeBSD$

PORTNAME=	opengrok
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/oracle/opengrok/releases/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and powerful code search and cross-reference engine

LICENSE=	CDDL APACHE20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.txt

RUN_DEPENDS=	exctags:devel/ctags

USE_JAVA=	yes
JAVA_VERSION=	1.8+
SHAREOWN=	www
SHAREGRP=	www
NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	CHANGES.txt EXAMPLE.txt README.txt NOTICE.txt
SUB_FILES=	opengrok
SUB_LIST+=	LIBFILES="${LIBFILES:S,^,${DATADIR}/lib/,}" \
		JARFILE="${JARFILE}"
PLIST_SUB=	T=${WEBAPP_HOME:S|^${LOCALBASE}/||} \
		OWNER=${SHAREOWN} GROUP=${SHAREGRP}

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		AS
OPTIONS_SINGLE_AS=	TOMCAT85 TOMCAT7 RESIN3
OPTIONS_DEFAULT=	TOMCAT85

TOMCAT7_VARS=	WEBAPP_HOME=${LOCALBASE}/apache-tomcat-7.0
TOMCAT85_VARS=	WEBAPP_HOME=${LOCALBASE}/apache-tomcat-8.5
RESIN3_VARS=	WEBAPP_HOME=${LOCALBASE}/resin3

TOMCAT7_BUILD_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat7
TOMCAT7_RUN_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat7
TOMCAT85_BUILD_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat85
TOMCAT85_RUN_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:www/tomcat85
RESIN3_BUILD_DEPENDS=	${WEBAPP_HOME}/lib/resin.jar:www/resin3
RESIN3_RUN_DEPENDS=	${WEBAPP_HOME}/lib/resin.jar:www/resin3

JARFILE=	${DATADIR}/opengrok.jar
LIBFILES=	ant.jar \
		bcel-6.0.jar \
		jrcs.jar \
		lucene-analyzers-common-6.5.0.jar \
		lucene-core-6.5.0.jar \
		lucene-queryparser-6.5.0.jar \
		lucene-suggest-6.5.0.jar \
		swing-layout-0.9.jar \
		json-simple-1.1.1.jar

WEBAPPS_DIR=	${WEBAPP_HOME:S|^${LOCALBASE}/||}/webapps

post-extract:
	@${MKDIR} ${WRKSRC}/lib/opengrok
	@${TAR} -xf ${WRKSRC}/lib/source.war -C ${WRKSRC}/lib/opengrok

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}
	(cd ${WRKSRC}/lib/opengrok && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF && \
		${MV} web.xml web.xml.sample)
	${INSTALL_DATA} ${LIBFILES:S,^,${WRKSRC}/lib/lib/,} \
		${STAGEDIR}${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/opengrok.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/opengrok ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
