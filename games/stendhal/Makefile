# Created by: Jordan Irwin <antumdeluge@gmail.com>
# $FreeBSD$

PORTNAME=		stendhal
PORTVERSION=		1.19
DISTVERSIONSUFFIX=	-src
CATEGORIES=		games java
MASTER_SITES=		SF/arianne/${PORTNAME}/${PORTVERSION}/

MAINTAINER=		antumdeluge@gmail.com
COMMENT=		Two-dimensional massively multi-player online RPG

LICENSE=		BSD2CLAUSE GPLv2
LICENSE_COMB=		multi

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_JAVA=		yes
JAVA_VERSION=		1.6+
USE_ANT=		yes
USES=			shebangfix

OPTIONS_MULTI=		COMPONENTS
OPTIONS_MULTI_COMPONENTS=	\
			CLIENT SERVER
OPTIONS_DEFAULT=	CLIENT

CLIENT_DESC=		Build game client
SERVER_DESC=		Build game server

OPTIONS_SUB=		yes

PLIST_SUB+=		PORTVERSION=${PORTVERSION} \
			JAVAJARDIR=${JAVAJARDIR}

.include <bsd.port.options.mk>

MKDIRS=			${STAGEDIR}${DATADIR} ${STAGEDIR}${DATADIR}/doc/Licenses \
			${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DATADIR}/log
CLIENTSTARTER=		stendhal-starter
CLIENTICON=		data/gui/StendhalIcon

SERVERSCRIPTS=		build/build_server_script

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ARGS+=		client_build
.endif

.if ${PORT_OPTIONS:MSERVER}
MAKE_ARGS+=		server_build
MKDIRS+=		${STAGEDIR}${DATADIR}/data/conf ${STAGEDIR}${DATADIR}/data/script
.endif

do-install:
	# COMMON
	@${MKDIR} ${MKDIRS}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DATADIR} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/libs/log4j.jar ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/libs/marauroa.jar ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA}	${WRKSRC}/README.txt ${STAGEDIR}${DATADIR}

	# CLIENT
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/libs/jorbis.jar ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/lib/${PORTNAME}.jar
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}-data-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/lib/${PORTNAME}-data.jar
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}-music-data-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/lib/${PORTNAME}-music-data.jar
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}-sound-data-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/lib/${PORTNAME}-sound-data.jar
	${INSTALL_DATA} ${WRKSRC}/build/lib/${CLIENTSTARTER}-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/${CLIENTSTARTER}.jar
	${INSTALL} ${FILESDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/.hotspotrc ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${CLIENTICON}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

	# SERVER
.if ${PORT_OPTIONS:MSERVER}
	${INSTALL_DATA} ${WRKSRC}/libs/groovy.jar ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/libs/guava.jar ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/libs/h2.jar ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/libs/simple.jar ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}-maps-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/lib/${PORTNAME}-maps.jar
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}-server-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/lib/${PORTNAME}-server.jar
	${INSTALL_DATA} ${WRKSRC}/build/lib/${PORTNAME}-xmlconf-${PORTVERSION}.jar \
		${STAGEDIR}${DATADIR}/lib/${PORTNAME}-xmlconf.jar
	@cd ${WRKSRC}/${SERVERSCRIPTS} && ${COPYTREE_SHARE} games ${STAGEDIR}${DATADIR}/data/script
	${INSTALL} ${FILESDIR}/${PORTNAME}-server \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/data/conf/admins.txt ${STAGEDIR}${DATADIR}/data/conf
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}-server.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
