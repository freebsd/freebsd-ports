# Created by: Dusan Vejnovic <freebsd@dussan.org>
# $FreeBSD$

PORTNAME=	gitblit
PORTVERSION=	1.8.0
PORTREVISION=	2
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

SUB_FILES=	pkg-message
PLIST_SUB+=	GB_DATAHOME=${PREFIX}/${PORTNAME} \
				GB_GROUP=${GROUPS} \
				GB_HOME=${GB_HOME} \
				GB_USER=${USERS}

OPTIONS_RADIO=			SQL WEBSERVER
OPTIONS_RADIO_SQL=		REDIS
OPTIONS_RADIO_WEBSERVER=APACHE HIAWATHA LIGHTTPD NGINX
HIAWATHA_DESC=			Hiawatha server support
NGINX_DESC=				Nginx server support
REDIS_RUN_DEPENDS=		redis-server:databases/redis

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USES=		apache:run,2.2+
.elif ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:www/lighttpd
.elif ${PORT_OPTIONS:MHIAWATHA}
RUN_DEPENDS+=	hiawatha:www/hiawatha
.elif ${PORT_OPTIONS:MNGINX}
RUN_DEPENDS+=	nginx:www/nginx
.endif

GB_HOME=	${PREFIX}/apache-tomcat-7.0/webapps/${PORTNAME}
RUN_DEPENDS+=	${LOCALBASE}/etc/rc.d/tomcat7:www/tomcat7

do-extract:
	${MKDIR} ${WRKSRC}
	${TAR} xf ${DISTDIR}/${DISTFILES} -C ${WRKSRC}/

do-install:
	${MKDIR} ${STAGEDIR}${GB_HOME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${GB_HOME})
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	(cd ${STAGEDIR}${GB_HOME}/WEB-INF/data && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PORTNAME})
	(cd ${STAGEDIR}${PREFIX}/${PORTNAME} && ${FIND} . -type f \
		-not -name '*.gitignore' -exec ${MV} {} {}.sample \;)

.include <bsd.port.mk>
