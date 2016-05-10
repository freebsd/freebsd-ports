# Created by: Dusan Vejnovic <freebsd@dussan.org>
# $FreeBSD$

PORTNAME=	gitblit
PORTVERSION=	1.7.1
CATEGORIES=	devel java
MASTER_SITES=	http://dl.bintray.com/${PORTNAME}/releases/
EXTRACT_SUFX=	.war

MAINTAINER=	freebsd@dussan.org
COMMENT=	Open-source servlet for Git repositories

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/WEB-INF/LICENSE

CONFLICTS=	${PORTNAME}-go-[0-9]*

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		www
GROUPS=		www

USE_JAVA=	yes
JAVA_VERSION=	1.7+

SUB_FILES=	pkg-message
PLIST_SUB+=	GB_DATAHOME=${PREFIX}/${PORTNAME} \
				GB_GROUP=${GROUPS} \
				GB_HOME=${GB_HOME} \
				GB_USER=${USERS}

OPTIONS_RADIO=			SQL WEBSERVER
OPTIONS_SINGLE=			TOMCAT
OPTIONS_RADIO_SQL=		REDIS
OPTIONS_RADIO_WEBSERVER=APACHE HIAWATHA LIGHTTPD NGINX
OPTIONS_SINGLE_TOMCAT=	TOMCAT6 TOMCAT7 TOMCAT8
HIAWATHA_DESC=			Hiawatha server support
NGINX_DESC=				Nginx server support
TOMCAT8_DESC=			Tomcat 8.x support
OPTIONS_DEFAULT=		TOMCAT7
REDIS_RUN_DEPENDS=		redis-server:databases/redis

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.elif ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:www/lighttpd
.elif ${PORT_OPTIONS:MHIAWATHA}
RUN_DEPENDS+=	hiawatha:www/hiawatha
.elif ${PORT_OPTIONS:MNGINX}
RUN_DEPENDS+=	nginx:www/nginx
.endif

.if ${PORT_OPTIONS:MTOMCAT6}
GB_HOME=	${PREFIX}/apache-tomcat-6.0/webapps/${PORTNAME}
RUN_DEPENDS+=	${PREFIX}/etc/rc.d/tomcat6:www/tomcat6
.elif ${PORT_OPTIONS:MTOMCAT7}
GB_HOME=	${PREFIX}/apache-tomcat-7.0/webapps/${PORTNAME}
RUN_DEPENDS+=	${PREFIX}/etc/rc.d/tomcat7:www/tomcat7
.elif ${PORT_OPTIONS:MTOMCAT8}
GB_HOME=	${PREFIX}/apache-tomcat-8.0/webapps/${PORTNAME}
RUN_DEPENDS+=	${PREFIX}/etc/rc.d/tomcat8:www/tomcat8
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${TAR} xf ${DISTDIR}/${DISTFILES} -C ${WRKSRC}/

do-install:
	${MKDIR} ${STAGEDIR}${GB_HOME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${GB_HOME})
	${CHMOD} -R 644 ${STAGEDIR}${GB_HOME}
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	(cd ${STAGEDIR}${GB_HOME}/WEB-INF/data && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX}/${PORTNAME} && ${FIND} . -type f \
		-not -name '*.gitignore' -exec ${MV} '{}' '{}'.sample \;)

.include <bsd.port.mk>
