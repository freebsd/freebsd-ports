# Created by: Jarrod Sayers <jarrod@downtools.com.au>
# $FreeBSD$

PORTNAME=	shoutcast
PORTVERSION=	2.0.0.29
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://download.nullsoft.com/shoutcast/tools/
DISTNAME=	sc_serv2_bsd_8_x_07_31_2011

MAINTAINER=	jarrod@downtools.com.au
COMMENT=	SHOUTcast Distributed Network Audio Server

RESTRICTED=	redistribution of software is not permitted
IA32_BINARY_PORT=	yes

USES=		dos2unix
NO_STAGE=	yes
DOS2UNIX_REGEX=	.*\.(conf|css|html|js|txt|xml)

USE_RC_SUBR=	shoutcast

CONFLICTS=	linux-shoutcast-[0-9]*
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	CONFIG_BUILDER DOCS EXAMPLES
CONFIG_BUILDER_DESC=	SHOUTcast Configuration Builder

SHOUTCASTUSER=	${PORTNAME}
SHOUTCASTGROUP=	${PORTNAME}
SHOUTCASTLDIR=	/var/log/${PORTNAME}
SHOUTCASTDIR=	/var/run/${PORTNAME}

SHOUTCAST_SUB=	SHOUTCASTUSER=${SHOUTCASTUSER} \
		SHOUTCASTGROUP=${SHOUTCASTGROUP} \
		SHOUTCASTLDIR=${SHOUTCASTLDIR} \
		SHOUTCASTDIR=${SHOUTCASTDIR}

PLIST_SUB=	${SHOUTCAST_SUB}

SUB_FILES=	pkg-message

SUB_LIST=	${SHOUTCAST_SUB}

USERS=		${SHOUTCASTUSER}
GROUPS=		${SHOUTCASTGROUP}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONFIG_BUILDER}
PLIST_SUB+=	CONFIG_BUILDER=""
.else
PLIST_SUB+=	CONFIG_BUILDER="@comment "
.endif

post-patch:
.for _file in basic debug public relay simple
	@${REINPLACE_CMD} -e '/sc_serv2 directory/d' \
		-e 's#=.*/\([^\.]*.log\)#=${SHOUTCASTLDIR}/\1#g' \
		-e 's#=control/#=${SHOUTCASTDIR}/#g' ${WRKSRC}/sc_serv_${_file}.conf
.endfor
.if ${PORT_OPTIONS:MCONFIG_BUILDER}
	@${REINPLACE_CMD} -e 's#<[^>]*>Windows<[^>]*>##g' \
		-e 's#<[^>]*>Macintosh<[^>]*>##g' ${WRKSRC}/config_builder/config_builder.html
	@${REINPLACE_CMD} -e 's#\(LogFile="\)\([^"/]*\)#\1${SHOUTCASTLDIR}/\2#g' \
		-e 's#\(ConfFile="\)\([^"/]*\)#\1${ETCDIR}/\2#g' \
		-e 's#\(BanFile="\)\([^"/]*\)#\1${SHOUTCASTDIR}/\2#g' \
		-e 's#\(RipFile="\)\([^"/]*\)#\1${SHOUTCASTDIR}/\2#g' ${WRKSRC}/config_builder/js/config_builder.js
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${PREFIX}/sbin
	${MKDIR} ${ETCDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${DOCSDIR}/changes.txt
	${INSTALL_DATA} ${WRKSRC}/docs/getting_started.txt ${DOCSDIR}/getting_started.txt
	${INSTALL_DATA} ${WRKSRC}/docs/sc_serv2.txt ${DOCSDIR}/sc_serv2.txt
	${INSTALL_DATA} ${WRKSRC}/docs/sc_serv2_authhash.txt ${DOCSDIR}/sc_serv2_authhash.txt
	${INSTALL_DATA} ${WRKSRC}/docs/sc_serv2_xml_responses.txt ${DOCSDIR}/sc_serv2_xml_responses.txt
	${INSTALL_DATA} ${WRKSRC}/docs/shoutcast_system_overview.txt ${DOCSDIR}/shoutcast_system_overview.txt
	${INSTALL_DATA} ${WRKSRC}/tos.txt ${DOCSDIR}/tos.txt
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/crossdomain.xml ${EXAMPLESDIR}/crossdomain.xml
	${INSTALL_DATA} ${WRKSRC}/sc_serv_basic.conf ${EXAMPLESDIR}/sc_serv_basic.conf
	${INSTALL_DATA} ${WRKSRC}/sc_serv_debug.conf ${EXAMPLESDIR}/sc_serv_debug.conf
	${INSTALL_DATA} ${WRKSRC}/sc_serv_public.conf ${EXAMPLESDIR}/sc_serv_public.conf
	${INSTALL_DATA} ${WRKSRC}/sc_serv_relay.conf ${EXAMPLESDIR}/sc_serv_relay.conf
	${INSTALL_DATA} ${WRKSRC}/sc_serv_simple.conf ${EXAMPLESDIR}/sc_serv_simple.conf
.endif
.if ${PORT_OPTIONS:MCONFIG_BUILDER}
	${MKDIR} ${WWWDIR}/config_builder
	${INSTALL_DATA} ${WRKSRC}/config_builder/config_builder.html ${WWWDIR}/config_builder/config_builder.html
	${MKDIR} ${WWWDIR}/config_builder/db
	${INSTALL_DATA} ${WRKSRC}/config_builder/db/config_builder_help.txt ${WWWDIR}/config_builder/db/config_builder_help.txt
	${MKDIR} ${WWWDIR}/config_builder/js
	${INSTALL_DATA} ${WRKSRC}/config_builder/js/config_builder.js ${WWWDIR}/config_builder/js/config_builder.js
	${INSTALL_DATA} ${WRKSRC}/config_builder/js/downloadify.js ${WWWDIR}/config_builder/js/downloadify.js
	${INSTALL_DATA} ${WRKSRC}/config_builder/js/mootools-1.3.js ${WWWDIR}/config_builder/js/mootools-1.3.js
	${INSTALL_DATA} ${WRKSRC}/config_builder/js/swfobject.js ${WWWDIR}/config_builder/js/swfobject.js
	${MKDIR} ${WWWDIR}/config_builder/res
	${INSTALL_DATA} ${WRKSRC}/config_builder/res/collapse.png ${WWWDIR}/config_builder/res/collapse.png
	${INSTALL_DATA} ${WRKSRC}/config_builder/res/config_builder.css ${WWWDIR}/config_builder/res/config_builder.css
	${INSTALL_DATA} ${WRKSRC}/config_builder/res/dl_button.png ${WWWDIR}/config_builder/res/dl_button.png
	${INSTALL_DATA} ${WRKSRC}/config_builder/res/downloadify.swf ${WWWDIR}/config_builder/res/downloadify.swf
	${INSTALL_DATA} ${WRKSRC}/config_builder/res/expand.png ${WWWDIR}/config_builder/res/expand.png
	${INSTALL_DATA} ${WRKSRC}/config_builder/res/sc_logo.png ${WWWDIR}/config_builder/res/sc_logo.png
.endif

post-install:
	${MKDIR} ${SHOUTCASTDIR} ${SHOUTCASTLDIR}
	@${CHMOD} 0750 ${SHOUTCASTDIR} ${SHOUTCASTLDIR}
	@${CHOWN} ${SHOUTCASTUSER}:${SHOUTCASTGROUP} ${SHOUTCASTDIR}
	@${CHOWN} ${SHOUTCASTUSER}:wheel ${SHOUTCASTLDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
