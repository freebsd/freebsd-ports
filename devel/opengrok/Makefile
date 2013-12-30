# $FreeBSD$

PORTNAME=	opengrok
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://hub.opensolaris.org/bin/download/Project+opengrok/files/

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Fast and powerful code search and cross-reference engine

LICENSE=	CDDL APACHE20
LICENSE_COMB=	multi

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

USE_JAVA=	yes
JAVA_VERSION=	1.6+
SHAREOWN=	www
SHAREGRP=	www
NO_BUILD=	yes
SUB_FILES=	opengrok
SUB_LIST+=	LIBFILES="${LIBFILES:S,^,${DATADIR}/,}" \
		JARFILE="${JARFILE}"
PLIST_SUB=	T=${WEBAPP_HOME:S|^${LOCALBASE}/||} \
		CONF_EXT=${CONF_EXT}
CONF_EXT=	sample

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT7 TOMCAT6 RESIN3
OPTIONS_DEFAULT=	TOMCAT6

NO_STAGE=	yes
.include <bsd.port.pre.mk>

JARFILE=	${DATADIR}/opengrok.jar
DOCS=		CHANGES.txt EXAMPLE.txt LICENSE.txt
LIBFILES=	ant.jar \
		bcel-5.2.jar \
		jrcs.jar \
		lucene-core-3.0.2.jar \
		lucene-spellchecker-3.0.2.jar \
		swing-layout-0.9.jar

.if ${PORT_OPTIONS:MTOMCAT7}
WEBAPP_HOME?=	${LOCALBASE}/apache-tomcat-7.0
BUILD_DEPENDS+=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
.endif

.if ${PORT_OPTIONS:MTOMCAT6}
WEBAPP_HOME?=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${WEBAPP_HOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MRESIN3}
WEBAPP_HOME?=	${LOCALBASE}/resin3
BUILD_DEPENDS+=	${WEBAPP_HOME}/lib/resin.jar:${PORTSDIR}/www/resin3
RUN_DEPENDS+=	${WEBAPP_HOME}/lib/resin.jar:${PORTSDIR}/www/resin3
.endif

WEBAPPS_DIR=	${WEBAPP_HOME:S|^${LOCALBASE}/||}/webapps

pre-everything::
.if ${PREFIX}!=${LOCALBASE}
	@${ECHO_MSG} "Warning: you changed prefix to ${PREFIX}"
	@${ECHO_MSG} "Default installation will not work if you installed"
	@${ECHO_MSG} "application server in different prefix"
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/lib/${PORTNAME}
	@${TAR} xf ${WRKSRC}/lib/source.war -C ${WRKSRC}/lib/${PORTNAME}

do-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}
	@${MV} ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml.${CONF_EXT}
	@cd ${WRKSRC}/lib/${PORTNAME} && ${COPYTREE_SHARE} \* ${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}

	@if [ ! -e "${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF/web.xml" ]; then \
			${ECHO_MSG} "	Installing local configuration file: ${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF/web.xml"; \
			${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml.${CONF_EXT} ${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF/web.xml; \
		else \
			${ECHO_MSG} "	Preserving local configuration file: ${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF/web.xml"; \
	fi;
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml.${CONF_EXT} ${PREFIX}/${WEBAPPS_DIR}/${PORTNAME}/WEB-INF

	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${LIBFILES:S,^,${WRKSRC}/lib/lib/,} ${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/opengrok.jar ${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/opengrok ${PREFIX}/bin

.include <bsd.port.post.mk>
