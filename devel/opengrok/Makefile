# $FreeBSD$

PORTNAME=	opengrok
PORTVERSION=	0.12.1
CATEGORIES=	devel java
MASTER_SITES=	http://java.net/projects/opengrok/downloads/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and powerful code search and cross-reference engine

LICENSE=	CDDL APACHE20
LICENSE_COMB=	multi

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www
NO_BUILD=	yes
PORTDOCS=	${DOCS}
SUB_FILES=	opengrok
SUB_LIST+=	LIBFILES="${LIBFILES:S,^,${DATADIR}/,}" \
		JARFILE="${JARFILE}"
PLIST_SUB=	T=${WEBAPP_HOME:S|^${LOCALBASE}/||} \
		OWNER=${SHAREOWN} GROUP=${SHAREGRP}

OPTIONS_SINGLE=		AS
OPTIONS_SINGLE_AS=	TOMCAT7 TOMCAT6 RESIN3
OPTIONS_DEFAULT=	TOMCAT6

TOMCAT6_BUILD_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
TOMCAT6_RUN_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
TOMCAT7_BUILD_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
TOMCAT7_RUN_DEPENDS=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RESIN3_BUILD_DEPENDS=	${WEBAPP_HOME}/lib/resin.jar:${PORTSDIR}/www/resin3
RESIN3_RUN_DEPENDS=	${WEBAPP_HOME}/lib/resin.jar:${PORTSDIR}/www/resin3

JARFILE=	${DATADIR}/opengrok.jar
DOCS=		CHANGES.txt EXAMPLE.txt LICENSE.txt
LIBFILES=	ant.jar \
		bcel-5.2.jar \
		jrcs.jar \
		lucene-core-4.7.1.jar \
		lucene-queryparser-4.7.1.jar \
		lucene-suggest-4.7.1.jar \
		swing-layout-0.9.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT7}
WEBAPP_HOME?=	${LOCALBASE}/apache-tomcat-7.0
.endif

.if ${PORT_OPTIONS:MTOMCAT6}
WEBAPP_HOME?=	${LOCALBASE}/apache-tomcat-6.0
.endif

.if ${PORT_OPTIONS:MRESIN3}
WEBAPP_HOME?=	${LOCALBASE}/resin3
.endif

WEBAPPS_DIR=	${WEBAPP_HOME:S|^${LOCALBASE}/||}/webapps

post-extract:
	@${MKDIR} ${WRKSRC}/lib/opengrok
	@${TAR} -xf ${WRKSRC}/lib/source.war -C ${WRKSRC}/lib/opengrok

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}
	(cd ${WRKSRC}/lib/opengrok && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF && \
		${MV} web.xml web.xml.sample)
	${INSTALL_DATA} ${LIBFILES:S,^,${WRKSRC}/lib/lib/,} \
		${STAGEDIR}${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/opengrok.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/opengrok ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
