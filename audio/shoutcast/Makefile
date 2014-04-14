# Created by: Jarrod Sayers <jarrod@downtools.com.au>
# $FreeBSD$

PORTNAME=	shoutcast
PORTVERSION=	2.2.1.109
CATEGORIES=	audio net
MASTER_SITES=	http://download.nullsoft.com/shoutcast/tools/
DISTNAME=	sc_serv2_bsd_8_x_11_29_2013

MAINTAINER=	jarrod@downtools.com.au
COMMENT=	SHOUTcast Distributed Network Audio Server

RESTRICTED=	redistribution of software is not permitted
IA32_BINARY_PORT=	yes

USES=	dos2unix
DOS2UNIX_REGEX=	.*\.(conf|css|html|js|txt|xml)

USE_RC_SUBR=	shoutcast

CONFLICTS=	linux-shoutcast-[0-9]*
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS_DEFAULT= CONFIG_BUILDER EXAMPLES
OPTIONS_DEFINE=	CONFIG_BUILDER DOCS EXAMPLES
CONFIG_BUILDER_DESC=	SHOUTcast Configuration Builder
EXAMPLE_DESC=	SHOUTcast Server Example Configuration Files

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

.if ${OSVERSION} >= 1000010
.if ${ARCH} == "i386"
RUN_DEPENDS+=   ${LOCALBASE}/lib/compat/libstdc++.so.6:${PORTSDIR}/misc/compat9x
.else
RUN_DEPENDS+=   ${LOCALBASE}/lib32/compat/libstdc++.so.6:${PORTSDIR}/misc/compat9x
.endif
.endif

.if ${PORT_OPTIONS:MCONFIG_BUILDER}
PLIST_SUB+=	CONFIG_BUILDER=""
.else
PLIST_SUB+=	CONFIG_BUILDER="@comment "
.endif

post-patch:
.for _file in basic debug public relay simple
	@${REINPLACE_CMD} -e '/sc_serv2 directory/d' \
		-e 's#=.*/\([^\.]*.log\)#=${SHOUTCASTLDIR}/\1#g' \
		-e 's#=control/#=${SHOUTCASTDIR}/#g' ${WRKSRC}/examples/sc_serv_${_file}.conf
.endfor
.if ${PORT_OPTIONS:MCONFIG_BUILDER}
	@${REINPLACE_CMD} -e 's#<[^>]*>Windows<[^>]*>##g' \
		-e 's#<[^>]*>Macintosh<[^>]*>##g' ${WRKSRC}/config_builder/config_builder.html
	@${REINPLACE_CMD} -e 's#\(LogFile="\)\([^"/]*\)#\1${SHOUTCASTLDIR}/\2#g' \
		-e 's#\(ConfFile="\)\([^"/]*\)#\1${STAGEDIR}${ETCDIR}/\2#g' \
		-e 's#\(BanFile="\)\([^"/]*\)#\1${SHOUTCASTDIR}/\2#g' \
		-e 's#\(RipFile="\)\([^"/]*\)#\1${SHOUTCASTDIR}/\2#g' ${WRKSRC}/config_builder/config_builder.js
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${SHOUTCASTLDIR}
	${MKDIR} ${STAGEDIR}${SHOUTCASTDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DNAS_Server_Changelog.html ${STAGEDIR}${DOCSDIR}/DNAS_Server_Changelog.html
	${INSTALL_DATA} ${WRKSRC}/Readme_DNAS_Server.html ${STAGEDIR}${DOCSDIR}/Readme_DNAS_Server.html
	${INSTALL_DATA} ${WRKSRC}/tos.txt ${STAGEDIR}${DOCSDIR}/tos.txt
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_XML_Responses.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_XML_Responses.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_Authhash_Management.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_Authhash_Management.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server.html
	${INSTALL_DATA} ${WRKSRC}/docs/Getting_Started.html ${STAGEDIR}${DOCSDIR}/docs/Getting_Started.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_JSON_Responses.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_JSON_Responses.html
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs/res
	${INSTALL_DATA} ${WRKSRC}/docs/res/Linux_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Linux_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Output_tag_configuration_error.png ${STAGEDIR}${DOCSDIR}/docs/res/Output_tag_configuration_error.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Ban_List_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Ban_List_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Start.png ${STAGEDIR}${DOCSDIR}/docs/res/Start.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Bandwidth_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Bandwidth_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Manual.png ${STAGEDIR}${DOCSDIR}/docs/res/Manual.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Completed.png ${STAGEDIR}${DOCSDIR}/docs/res/Completed.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Simple.png ${STAGEDIR}${DOCSDIR}/docs/res/Simple.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Error.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Error.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Log_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Log_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Builder_Mode.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Builder_Mode.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Select_Source_DSP_in_Winamp.png ${STAGEDIR}${DOCSDIR}/docs/res/Select_Source_DSP_in_Winamp.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Removed.png ${STAGEDIR}${DOCSDIR}/docs/res/Removed.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Linux.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Linux.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Windows_Service_Install_Failure.png ${STAGEDIR}${DOCSDIR}/docs/res/Windows_Service_Install_Failure.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Summary_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Summary_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Admin_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Admin_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Setup_Mode.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Setup_Mode.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Invalid_Configuration_Item.png ${STAGEDIR}${DOCSDIR}/docs/res/Invalid_Configuration_Item.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Summary_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Summary_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Example_Windows_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Example_Windows_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Source_Login_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Source_Login_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Streams_Summary_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Streams_Summary_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Example_Linux_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Example_Linux_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Linux_Daemon_Mode.png ${STAGEDIR}${DOCSDIR}/docs/res/Linux_Daemon_Mode.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Admin_Config_Reload.png ${STAGEDIR}${DOCSDIR}/docs/res/Admin_Config_Reload.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Windows_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Windows_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Reserved_List_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Reserved_List_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Summary.png ${STAGEDIR}${DOCSDIR}/docs/res/Summary.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Setup_Mode_Error.png ${STAGEDIR}${DOCSDIR}/docs/res/Setup_Mode_Error.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Editing.png ${STAGEDIR}${DOCSDIR}/docs/res/Editing.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Windows.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Windows.png

.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_basic.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_basic.conf
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_debug.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_debug.conf
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_public.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_public.conf
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_relay.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_relay.conf
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_simple.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_simple.conf
.endif
.if ${PORT_OPTIONS:MCONFIG_BUILDER}
	${MKDIR} ${STAGEDIR}${WWWDIR}/config_builder
	${INSTALL_DATA} ${WRKSRC}/config_builder/config_builder.html ${STAGEDIR}${WWWDIR}/config_builder/config_builder.html
	${INSTALL_DATA} ${WRKSRC}/config_builder/config_builder.txt ${STAGEDIR}${WWWDIR}/config_builder/config_builder.txt
	${INSTALL_DATA} ${WRKSRC}/config_builder/config_builder.js ${STAGEDIR}${WWWDIR}/config_builder/config_builder.js
	${INSTALL_DATA} ${WRKSRC}/config_builder/config_builder.css ${STAGEDIR}${WWWDIR}/config_builder/config_builder.css
.endif

.include <bsd.port.mk>
