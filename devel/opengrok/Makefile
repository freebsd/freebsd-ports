# New ports collection makefile for:	opengrok
# Date created:		10/13/2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	opengrok
PORTVERSION=	0.11.1
CATEGORIES=	devel java
MASTER_SITES=	http://hub.opensolaris.org/bin/download/Project+opengrok/files/

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Fast and powerful code search and cross-reference engine

LICENSE=	CDDL AL2
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
PLIST_SUB=	T=${WEBAPP_DIRS:S|^${LOCALBASE}/||} \
		CONF_EXT=${CONF_EXT}
CONF_EXT=	sample

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT5 TOMCAT6 RESIN3
OPTIONS_DEFAULT=	TOMCAT6

.include <bsd.port.pre.mk>

JARFILE=	${DATADIR}/opengrok.jar
DOCS=		CHANGES.txt EXAMPLE.txt LICENSE.txt
LIBFILES=	ant.jar \
		bcel-5.2.jar \
		jrcs.jar \
		lucene-core-3.0.2.jar \
		lucene-spellchecker-3.0.2.jar \
		swing-layout-0.9.jar

.if ${PORT_OPTIONS:MTOMCAT6}
WEBAPP_DIRS=	apache-tomcat-6.0
BUILD_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT5}
WEBAPP_DIRS=	tomcat5.5
BUILD_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
.endif

.if ${PORT_OPTIONS:MRESIN3}
WEBAPP_DIRS=	resin3
BUILD_DEPENDS+=	${LOCALBASE}/resin3/lib/resin.jar:${PORTSDIR}/www/resin3
RUN_DEPENDS+=	${LOCALBASE}/resin3/lib/resin.jar:${PORTSDIR}/www/resin3
.endif

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
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${PREFIX}/${WEBAPP_DIRS}/webapps/${PORTNAME}
	@${MV} ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml.${CONF_EXT}
	@cd ${WRKSRC}/lib/${PORTNAME} && ${COPYTREE_SHARE} \* ${PREFIX}/${WEBAPP_DIRS}/webapps/${PORTNAME}

	@if [ ! -e "${PREFIX}/${WEBAPP_DIRS}/webapps/${PORTNAME}/WEB-INF/web.xml" ]; then \
			${ECHO_MSG} "	Installing local configuration file: ${PREFIX}/${WEBAPP_DIRS}/webapps/${PORTNAME}/WEB-INF/web.xml"; \
			${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml.${CONF_EXT} ${PREFIX}/${WEBAPP_DIRS}/webapps/${PORTNAME}/WEB-INF/web.xml; \
		else \
			${ECHO_MSG} "	Preserving local configuration file: ${PREFIX}/${WEBAPP_DIRS}/webapps/${PORTNAME}/WEB-INF/web.xml"; \
	fi;
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}/WEB-INF/web.xml.${CONF_EXT} ${PREFIX}/${WEBAPP_DIRS}/webapps/${PORTNAME}/WEB-INF

	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${LIBFILES:S,^,${WRKSRC}/lib/lib/,} ${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/lib/opengrok.jar ${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/opengrok ${PREFIX}/bin

.include <bsd.port.post.mk>
