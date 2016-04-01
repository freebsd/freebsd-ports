# Created by: Jarrod Sayers <jarrod@downtools.com.au>
# $FreeBSD$

PORTNAME=	shoutcast
PORTVERSION=	2.4.7.256
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://download.nullsoft.com/shoutcast/tools/
DISTNAME=	sc_serv2_bsd-latest

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	SHOUTcast Distributed Network Audio Server

RESTRICTED=	redistribution of software is not permitted
IA32_BINARY_PORT=	yes

USES=		dos2unix shebangfix
DOS2UNIX_REGEX=	.*\.(conf|css|html|js|txt|xml)
bash_CMD=	${SH}
SHEBANG_FILES=	setup.sh

USE_RC_SUBR=	shoutcast

CONFLICTS=	linux-shoutcast-[0-9]*
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS_DEFAULT=	SERVERSETUP EXAMPLES
OPTIONS_DEFINE=	SERVERSETUP DOCS EXAMPLES
OPTIONS_SUB=	yes
SETUPSERVER_DESC=	SHOUTcast Server Setup Tools
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

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000010
.if ${ARCH} == "i386"
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:misc/compat9x
.else
RUN_DEPENDS+=	${LOCALBASE}/lib32/compat/libstdc++.so.6:misc/compat9x
.endif
.endif

post-patch:
.for _file in basic public relay simple
	@${REINPLACE_CMD} -e '/sc_serv2 directory/d' \
		-e 's#=.*/\([^\.]*.log\)#=${SHOUTCASTLDIR}/\1#g' \
		-e 's#=control/#=${SHOUTCASTDIR}/#g' ${WRKSRC}/examples/sc_serv_${_file}.conf
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${SHOUTCASTLDIR}
	${MKDIR} ${STAGEDIR}${SHOUTCASTDIR}
	${MKDIR} ${STAGEDIR}${SHOUTCASTDIR}/logs
	${MKDIR} ${STAGEDIR}${SHOUTCASTDIR}/control

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DNAS_Server_Changelog.html ${STAGEDIR}${DOCSDIR}/DNAS_Server_Changelog.html
	${INSTALL_DATA} ${WRKSRC}/Readme_DNAS_Server.html ${STAGEDIR}${DOCSDIR}/Readme_DNAS_Server.html
	${INSTALL_DATA} ${WRKSRC}/tos.txt ${STAGEDIR}${DOCSDIR}/tos.txt
	${INSTALL_DATA} ${WRKSRC}/cacert.pem ${STAGEDIR}${DOCSDIR}/cacert.pem
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/Getting_Started.html ${STAGEDIR}${DOCSDIR}/docs/Getting_Started.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_XML_Responses.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_XML_Responses.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_Authhash_Management.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_Authhash_Management.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_JSON_Responses.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_JSON_Responses.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_CDN_Management.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_CDN_Management.html
	${INSTALL_DATA} ${WRKSRC}/docs/DNAS_Server_Source_Support.html ${STAGEDIR}${DOCSDIR}/docs/DNAS_Server_Source_Support.html
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs/res
	${INSTALL_DATA} ${WRKSRC}/docs/res/Linux_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Linux_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Output_tag_configuration_error.png ${STAGEDIR}${DOCSDIR}/docs/res/Output_tag_configuration_error.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Ban_List_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Ban_List_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Blocked_User_Agent_List_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Blocked_User_Agent_List_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Start.png ${STAGEDIR}${DOCSDIR}/docs/res/Start.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Bandwidth_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Bandwidth_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Manual.png ${STAGEDIR}${DOCSDIR}/docs/res/Manual.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Completed.png ${STAGEDIR}${DOCSDIR}/docs/res/Completed.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Simple.png ${STAGEDIR}${DOCSDIR}/docs/res/Simple.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Error.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Error.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Log_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Log_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Source_Connection_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Source_Connection_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Select_Source_DSP_in_Winamp.png ${STAGEDIR}${DOCSDIR}/docs/res/Select_Source_DSP_in_Winamp.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Linux.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Linux.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Windows_Service_Install_Failure.png ${STAGEDIR}${DOCSDIR}/docs/res/Windows_Service_Install_Failure.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Summary_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Summary_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Admin_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Admin_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Streams_Summary_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Streams_Summary_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Setup_Mode.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Setup_Mode.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Invalid_Configuration_Item.png ${STAGEDIR}${DOCSDIR}/docs/res/Invalid_Configuration_Item.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Server_Summary_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Server_Summary_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Example_Windows_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Example_Windows_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Example_Linux_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Example_Linux_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Linux_Daemon_Mode.png ${STAGEDIR}${DOCSDIR}/docs/res/Linux_Daemon_Mode.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Windows_Console.png ${STAGEDIR}${DOCSDIR}/docs/res/Windows_Console.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Stream_Reserved_List_Page.png ${STAGEDIR}${DOCSDIR}/docs/res/Stream_Reserved_List_Page.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Summary.png ${STAGEDIR}${DOCSDIR}/docs/res/Summary.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Setup_Mode_Error.png ${STAGEDIR}${DOCSDIR}/docs/res/Setup_Mode_Error.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Editing.png ${STAGEDIR}${DOCSDIR}/docs/res/Editing.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/Console_Windows.png ${STAGEDIR}${DOCSDIR}/docs/res/Console_Windows.png
	${INSTALL_DATA} ${WRKSRC}/docs/res/View_Source_Connection_Details.png ${STAGEDIR}${DOCSDIR}/docs/res/View_Source_Connection_Details.png

do-install-SERVERSETUP-on:
	${MKDIR} ${STAGEDIR}${WWWDIR}/setup
	${INSTALL_DATA} ${WRKSRC}/setup.sh ${STAGEDIR}${WWWDIR}/setup.sh
	${INSTALL_DATA} ${WRKSRC}/setup/setup.js ${STAGEDIR}${WWWDIR}/setup/setup.js
	${INSTALL_DATA} ${WRKSRC}/setup/setup.html ${STAGEDIR}${WWWDIR}/setup/setup.html
	${INSTALL_DATA} ${WRKSRC}/setup/setup.txt ${STAGEDIR}${WWWDIR}/setup/setup.txt

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_basic.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_basic.conf
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_public.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_public.conf
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_relay.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_relay.conf
	${INSTALL_DATA} ${WRKSRC}/examples/sc_serv_simple.conf ${STAGEDIR}${EXAMPLESDIR}/sc_serv_simple.conf

.include <bsd.port.mk>
