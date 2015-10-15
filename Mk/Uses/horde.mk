# $FreeBSD$
#
# Feature:	horde
# Usage:	USES=horde
# Valid ARGS:	none
#
# MAINTAINER=	horde@FreeBSD.org

.if !defined(_INCLUDE_USES_HORDE_MK)
_INCLUDE_USES_HORDE_MK=	yes

MASTER_SITES?=	http://pear.horde.org/get/

BUILD_DEPENDS+=	${PEARDIR}/.channels/pear.horde.org.reg:${PORTSDIR}/devel/pear-channel-horde
RUN_DEPENDS+=	${PEARDIR}/.channels/pear.horde.org.reg:${PORTSDIR}/devel/pear-channel-horde

PKGNAMEPREFIX?=	pear-
HORDE_DIR?=	www/horde

CONFLICTS+=	horde3-*.[0-9]*

CPE_VENDOR?=	horde

DIST_SUBDIR=	Horde
PEAR_CHANNEL=	horde

horde-Horde_ActiveSync-DEPEND=	${PEARDIR}/Horde/ActiveSync.php:${PORTSDIR}/comms/pear-Horde_ActiveSync
horde-Horde_Alarm-DEPEND=	${PEARDIR}/Horde/Alarm.php:${PORTSDIR}/devel/pear-Horde_Alarm
horde-Horde_Auth-DEPEND=	${PEARDIR}/Horde/Auth.php:${PORTSDIR}/security/pear-Horde_Auth
horde-Horde_Autoloader-DEPEND=	${PEARDIR}/Horde/Autoloader.php:${PORTSDIR}/devel/pear-Horde_Autoloader
horde-Horde_Autoloader_Cache-DEPEND=	${PEARDIR}/Horde/Autoloader/Cache.php:${PORTSDIR}/devel/pear-Horde_Autoloader_Cache
horde-Horde_Argv-DEPEND=	${PEARDIR}/Horde/Argv/Parser.php:${PORTSDIR}/devel/pear-Horde_Argv
horde-Horde_Browser-DEPEND=	${PEARDIR}/Horde/Browser.php:${PORTSDIR}/www/pear-Horde_Browser
horde-Horde_Cache-DEPEND=	${PEARDIR}/Horde/Cache.php:${PORTSDIR}/devel/pear-Horde_Cache
horde-Horde_Cli-DEPEND=		${PEARDIR}/Horde/Cli.php:${PORTSDIR}/devel/pear-Horde_Cli
horde-Horde_Compress-DEPEND=	${PEARDIR}/Horde/Compress.php:${PORTSDIR}/archivers/pear-Horde_Compress
horde-Horde_Compress_Fast-DEPEND=	${PEARDIR}/Horde/Compress/Fast.php:${PORTSDIR}/archivers/pear-Horde_Compress_Fast
horde-Horde_Constraint-DEPEND=	${PEARDIR}/Horde/Constraint.php:${PORTSDIR}/devel/pear-Horde_Constraint
horde-Horde_Controller-DEPEND=	${PEARDIR}/Horde/Controller.php:${PORTSDIR}/devel/pear-Horde_Controller
horde-Horde_Core-DEPEND=	${PEARDIR}/Horde.php:${PORTSDIR}/devel/pear-Horde_Core
horde-Horde_Crypt-DEPEND=	${PEARDIR}/Horde/Crypt.php:${PORTSDIR}/security/pear-Horde_Crypt
horde-Horde_Crypt_Blowfish-DEPEND=	${PEARDIR}/Horde/Crypt/Blowfish.php:${PORTSDIR}/security/pear-Horde_Crypt_Blowfish
horde-Horde_CssMinify-DEPEND=	${PEARDIR}/Horde/CssMinify.php:${PORTSDIR}/textproc/pear-Horde_CssMinify
horde-Horde_Css_Parser-DEPEND=	${PEARDIR}/Horde/Css/Parser.php:${PORTSDIR}/www/pear-Horde_Css_Parser
horde-Horde_Data-DEPEND=	${PEARDIR}/Horde/Data.php:${PORTSDIR}/devel/pear-Horde_Data
horde-Horde_Date-DEPEND=	${PEARDIR}/Horde/Date.php:${PORTSDIR}/devel/pear-Horde_Date
horde-Horde_Date_Parser-DEPEND=	${PEARDIR}/Horde/Date/Parser.php:${PORTSDIR}/devel/pear-Horde_Date_Parser
horde-Horde_Dav-DEPEND=		${PEARDIR}/Horde/Dav/Client.php:${PORTSDIR}/www/pear-Horde_Dav
horde-Horde_Db-DEPEND=		${PEARDIR}/Horde/Db.php:${PORTSDIR}/databases/pear-Horde_Db
horde-Horde_Editor-DEPEND=	${PEARDIR}/Horde/Editor.php:${PORTSDIR}/www/pear-Horde_Editor
horde-Horde_Exception-DEPEND=	${PEARDIR}/Horde/Exception.php:${PORTSDIR}/devel/pear-Horde_Exception	
horde-Horde_Feed-DEPEND=	${PEARDIR}/Horde/Feed.php:${PORTSDIR}/www/pear-Horde_Feed
horde-Horde_Form-DEPEND=	${PEARDIR}/Horde/Form.php:${PORTSDIR}/www/pear-Horde_Form
horde-Horde_Group-DEPEND=	${PEARDIR}/Horde/Group/Base.php:${PORTSDIR}/security/pear-Horde_Group
horde-Horde_HashTable-DEPEND=	${PEARDIR}/Horde/HashTable/Base.php:${PORTSDIR}/databases/pear-Horde_HashTable
horde-Horde_History-DEPEND=	${PEARDIR}/Horde/History.php:${PORTSDIR}/devel/pear-Horde_History
horde-Horde_Http-DEPEND=	${PEARDIR}/Horde/Http.php:${PORTSDIR}/www/pear-Horde_Http
horde-Horde_Icalendar-DEPEND=	${PEARDIR}/Horde/Icalendar.php:${PORTSDIR}/devel/pear-Horde_Icalendar
horde-Horde_Idna-DEPEND=	${PEARDIR}/Horde/Idna.php:${PORTSDIR}/dns/pear-Horde_Idna
horde-Horde_Image-DEPEND=	${PEARDIR}/Horde/Image.php:${PORTSDIR}/graphics/pear-Horde_Image
horde-Horde_Imap_Client-DEPEND=	${PEARDIR}/Horde/Imap/Client.php:${PORTSDIR}/mail/pear-Horde_Imap_Client
horde-Horde_Imsp-DEPEND=	${PEARDIR}/Horde/Imsp.php:${PORTSDIR}/databases/pear-Horde_Imsp
horde-Horde_Itip-DEPEND=	${PEARDIR}/Horde/Itip.php:${PORTSDIR}/devel/pear-Horde_Itip
horde-Horde_Injector-DEPEND=	${PEARDIR}/Horde/Injector.php:${PORTSDIR}/devel/pear-Horde_Injector
horde-Horde_JavascriptMinify-DEPEND=	${PEARDIR}/Horde/JavascriptMinify.php:${PORTSDIR}/textproc/pear-Horde_JavascriptMinify
horde-Horde_Kolab_Format-DEPEND=	${PEARDIR}/Horde/Kolab/Format.php:${PORTSDIR}/textproc/pear-Horde_Kolab_Format
horde-Horde_Kolab_Server-DEPEND=	${PEARDIR}/Horde/Kolab/Server/Factory.php:${PORTSDIR}/net/pear-Horde_Kolab_Server
horde-Horde_Kolab_Session-DEPEND=	${PEARDIR}/Horde/Kolab/Session.php:${PORTSDIR}/net/pear-Horde_Kolab_Session
horde-Horde_Kolab_Storage-DEPEND=	${PEARDIR}/Horde/Kolab/Storage.php:${PORTSDIR}/mail/pear-Horde_Kolab_Storage
horde-Horde_Ldap-DEPEND=	${PEARDIR}/Horde/Ldap.php:${PORTSDIR}/net/pear-Horde_Ldap
horde-Horde_ListHeaders-DEPEND=	${PEARDIR}/Horde/ListHeaders.php:${PORTSDIR}/mail/pear-Horde_ListHeaders
horde-Horde_Lock-DEPEND=	${PEARDIR}/Horde/Lock.php:${PORTSDIR}/devel/pear-Horde_Lock
horde-Horde_Log-DEPEND=		${PEARDIR}/Horde/Log.php:${PORTSDIR}/sysutils/pear-Horde_Log
horde-Horde_LoginTasks-DEPEND=	${PEARDIR}/Horde/LoginTasks.php:${PORTSDIR}/devel/pear-Horde_LoginTasks
horde-Horde_Mail-DEPEND=	${PEARDIR}/Horde/Mail/Transport.php:${PORTSDIR}/mail/pear-Horde_Mail
horde-Horde_Mail_Autoconfig-DEPEND=	${PEARDIR}/Horde/Mail/Autoconfig.php:${PORTSDIR}/mail/pear-Horde_Mail_Autoconfig
horde-Horde_Mapi-DEPEND=	${PEARDIR}/Horde/Mapi.php:${PORTSDIR}/mail/pear-Horde_Mapi
horde-Horde_Memcache-DEPEND=	${PEARDIR}/Horde/Memcache.php:${PORTSDIR}/databases/pear-Horde_Memcache
horde-Horde_Mime-DEPEND=	${PEARDIR}/Horde/Mime.php:${PORTSDIR}/mail/pear-Horde_Mime
horde-Horde_Mime_Viewer-DEPEND=	${PEARDIR}/Horde/Mime/Viewer.php:${PORTSDIR}/mail/pear-Horde_Mime_Viewer
horde-Horde_Mongo-DEPEND=	${PEARDIR}/Horde/Mongo/Client.php:${PORTSDIR}/databases/pear-Horde_Mongo
horde-Horde_Nls-DEPEND=		${PEARDIR}/Horde/Nls.php:${PORTSDIR}/devel/pear-Horde_Nls
horde-Horde_Notification-DEPEND=	${PEARDIR}/Horde/Notification.php:${PORTSDIR}/devel/pear-Horde_Notification
horde-Horde_Oauth-DEPEND=	${PEARDIR}/Horde/Oauth/Consumer.php:${PORTSDIR}/security/pear-Horde_Oauth
horde-Horde_Pack-DEPEND=	${PEARDIR}/Horde/Pack.php:${PORTSDIR}/archivers/pear-Horde_Pack
horde-Horde_Pdf-DEPEND=		${PEARDIR}/Horde/Pdf/Writer.php:${PORTSDIR}/textproc/pear-Horde_Pdf
horde-Horde_Perms-DEPEND=	${PEARDIR}/Horde/Perms.php:${PORTSDIR}/security/pear-Horde_Perms
horde-Horde_Prefs-DEPEND=	${PEARDIR}/Horde/Prefs.php:${PORTSDIR}/devel/pear-Horde_Prefs
horde-Horde_Queue-DEPEND=	${PEARDIR}/Horde/Queue/Runner.php:${PORTSDIR}/devel/pear-Horde_Queue
horde-Horde_Rdo-DEPEND=		${PEARDIR}/Horde/Rdo.php:${PORTSDIR}/devel/pear-Horde_Rdo
horde-Horde_Role-DEPEND=	${PEARDIR}/PEAR/Installer/Role/Horde/Role.php:${PORTSDIR}/devel/pear-Horde_Role
horde-Horde_Rpc-DEPEND=		${PEARDIR}/Horde/Rpc.php:${PORTSDIR}/net/pear-Horde_Rpc
horde-Horde_Routes-DEPEND=	${PEARDIR}/Horde/Routes/Route.php:${PORTSDIR}/www/pear-Horde_Routes
horde-Horde_Secret-DEPEND=	${PEARDIR}/Horde/Secret.php:${PORTSDIR}/security/pear-Horde_Secret
horde-Horde_Serialize-DEPEND=	${PEARDIR}/Horde/Serialize.php:${PORTSDIR}/devel/pear-Horde_Serialize
horde-Horde_SessionHandler-DEPEND=	${PEARDIR}/Horde/SessionHandler.php:${PORTSDIR}/www/pear-Horde_SessionHandler
horde-Horde_Scheduler-DEPEND=	${PEARDIR}/Horde/Scheduler.php:${PORTSDIR}/devel/pear-Horde_Scheduler
horde-Horde_Scribe-DEPEND=	${PEARDIR}/Horde/Scribe.php:${PORTSDIR}/net/pear-Horde_Scribe
horde-Horde_Share-DEPEND=	${PEARDIR}/Horde/Share/Base.php:${PORTSDIR}/security/pear-Horde_Share
horde-Horde_Smtp-DEPEND=	${PEARDIR}/Horde/Smtp.php:${PORTSDIR}/mail/pear-Horde_Smtp
horde-Horde_Socket_Client-DEPEND=	${PEARDIR}/Horde/Socket/Client.php:${PORTSDIR}/net/pear-Horde_Socket_Client
horde-Horde_SpellChecker-DEPEND=	${PEARDIR}/Horde/SpellChecker.php:${PORTSDIR}/textproc/pear-Horde_SpellChecker
horde-Horde_Stream-DEPEND=	${PEARDIR}/Horde/Stream.php:${PORTSDIR}/devel/pear-Horde_Stream
horde-Horde_Stream_Filter-DEPEND=	${PEARDIR}/Horde/Stream/Filter/Crc32.php:${PORTSDIR}/devel/pear-Horde_Stream_Filter
horde-Horde_Stream_Wrapper-DEPEND=	${PEARDIR}/Horde/Stream/Wrapper/StringStream.php:${PORTSDIR}/devel/pear-Horde_Stream_Wrapper
horde-Horde_Service_Facebook-DEPEND=	${PEARDIR}/Horde/Service/Facebook.php:${PORTSDIR}/www/pear-Horde_Service_Facebook
horde-Horde_Service_Twitter-DEPEND=	${PEARDIR}/Horde/Service/Twitter.php:${PORTSDIR}/www/pear-Horde_Service_Twitter
horde-Horde_Service_UrlShortener-DEPEND=	${PEARDIR}/Horde/Service/UrlShortener.php:${PORTSDIR}/www/pear-Horde_Service_UrlShortener
horde-Horde_Service_Weather-DEPEND=	${PEARDIR}/Horde/Service/Weather.php:${PORTSDIR}/www/pear-Horde_Service_Weather
horde-Horde_Support-DEPEND=	${PEARDIR}/Horde/Support/Array.php:${PORTSDIR}/devel/pear-Horde_Support
horde-Horde_SyncMl-DEPEND=	${PEARDIR}/Horde/SyncMl.php:${PORTSDIR}/comms/pear-Horde_SyncMl
horde-Horde_Url-DEPEND=		${PEARDIR}/Horde/Url.php:${PORTSDIR}/net/pear-Horde_Url	
horde-Horde_Util-DEPEND=	${PEARDIR}/Horde/Util.php:${PORTSDIR}/devel/pear-Horde_Util	
horde-Horde_Template-DEPEND=	${PEARDIR}/Horde/Template.php:${PORTSDIR}/www/pear-Horde_Template
horde-Horde_Text_Diff-DEPEND=	${PEARDIR}/Horde/Text/Diff.php:${PORTSDIR}/textproc/pear-Horde_Text_Diff
horde-Horde_Text_Filter-DEPEND=	${PEARDIR}/Horde/Text/Filter.php:${PORTSDIR}/textproc/pear-Horde_Text_Filter
horde-Horde_Text_Filter_Csstidy-DEPEND=	${PEARDIR}/Horde/Text/Filter/Csstidy.php:${PORTSDIR}/textproc/pear-Horde_Text_Filter_Csstidy
horde-Horde_Text_Flowed-DEPEND=	${PEARDIR}/Horde/Text/Flowed.php:${PORTSDIR}/textproc/pear-Horde_Text_Flowed
horde-Horde_Thrift-DEPEND=	${PEARDIR}/Horde/Thrift.php:${PORTSDIR}/devel/pear-Horde_Thrift
horde-Horde_Timezone-DEPEND=	${PEARDIR}/Horde/Timezone.php:${PORTSDIR}/devel/pear-Horde_Timezone
horde-Horde_Token-DEPEND=	${PEARDIR}/Horde/Token.php:${PORTSDIR}/devel/pear-Horde_Token
horde-Horde_Translation-DEPEND=	${PEARDIR}/Horde/Translation.php:${PORTSDIR}/devel/pear-Horde_Translation
horde-Horde_Tree-DEPEND=	${PEARDIR}/Horde/Tree.php:${PORTSDIR}/devel/pear-Horde_Tree
horde-Horde_Vfs-DEPEND=		${PEARDIR}/Horde/Vfs.php:${PORTSDIR}/sysutils/pear-Horde_Vfs
horde-Horde_View-DEPEND=	${PEARDIR}/Horde/View.php:${PORTSDIR}/devel/pear-Horde_View
horde-Horde_Xml_Element-DEPEND=	${PEARDIR}/Horde/Xml/Element.php:${PORTSDIR}/textproc/pear-Horde_Xml_Element
horde-Horde_Xml_Wbxml-DEPEND=	${PEARDIR}/Horde/Xml/Wbxml.php:${PORTSDIR}/textproc/pear-Horde_Xml_Wbxml
horde-content-DEPEND=		${LOCALBASE}/${HORDE_DIR}/content/lib/Tagger.php:${PORTSDIR}/devel/horde-content
horde-gollem-DEPEND=		${LOCALBASE}/${HORDE_DIR}/gollem/index.php:${PORTSDIR}/ftp/horde-gollem
horde-horde-DEPEND=		${LOCALBASE}/${HORDE_DIR}/index.php:${PORTSDIR}/www/horde-base
horde-imp-DEPEND=		${LOCALBASE}/${HORDE_DIR}/imp/index.php:${PORTSDIR}/mail/horde-imp
horde-ingo-DEPEND=		${LOCALBASE}/${HORDE_DIR}/ingo/index.php:${PORTSDIR}/mail/horde-ingo
horde-kronolith-DEPEND=		${LOCALBASE}/${HORDE_DIR}/kronolith/index.php:${PORTSDIR}/deskutils/horde-kronolith
horde-mnemo-DEPEND=		${LOCALBASE}/${HORDE_DIR}/mnemo/index.php:${PORTSDIR}/deskutils/horde-mnemo
horde-nag-DEPEND=		${LOCALBASE}/${HORDE_DIR}/nag/index.php:${PORTSDIR}/deskutils/horde-nag
horde-timeobjects-DEPEND=	${LOCALBASE}/${HORDE_DIR}/timeobjects/lib/Driver.php:${PORTSDIR}/devel/horde-timeobjects
horde-trean-DEPEND=		${LOCALBASE}/${HORDE_DIR}/trean/index.php:${PORTSDIR}/www/horde-trean
horde-turba-DEPEND=		${LOCALBASE}/${HORDE_DIR}/turba/index.php:${PORTSDIR}/mail/horde-turba

.if defined(USE_HORDE_RUN)
. for DEP in ${USE_HORDE_RUN}
.  if !defined(horde-${DEP}-DEPEND)
UNKNOWN_HORDE_PACKAGES+=	${DEP}
.  else
RUN_DEPENDS+=	${horde-${DEP}-DEPEND}
.  endif
. endfor
.endif

.if defined(USE_HORDE_BUILD)
. for DEP in ${USE_HORDE_BUILD}
.  if !defined(horde-${DEP}-DEPEND)
UNKNOWN_HORDE_PACKAGES+=	${DEP}
.  else
BUILD_DEPENDS+=	${horde-${DEP}-DEPEND}
.  endif
. endfor
.endif

.if defined(UNKNOWN_HORDE_PACKAGES)
IGNORE=	unknown Horde package(s): ${UNKNOWN_HORDE_PACKAGES}
.endif

.include "${USESDIR}/pear.mk"
.endif
