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

HORDE_DIR?=	www/horde

CONFLICTS+=	horde3-*.[0-9]*

CPE_VENDOR?=	horde

DIST_SUBDIR=	Horde
PEAR_CHANNEL=	horde

horde-Horde_ActiveSync-DEPEND=	${PEARDIR}/Horde/ActiveSync.php:comms/pear-Horde_ActiveSync
horde-Horde_Alarm-DEPEND=	${PEARDIR}/Horde/Alarm.php:devel/pear-Horde_Alarm
horde-Horde_Auth-DEPEND=	${PEARDIR}/Horde/Auth.php:security/pear-Horde_Auth
horde-Horde_Autoloader-DEPEND=	${PEARDIR}/Horde/Autoloader.php:devel/pear-Horde_Autoloader
horde-Horde_Autoloader_Cache-DEPEND=	${PEARDIR}/Horde/Autoloader/Cache.php:devel/pear-Horde_Autoloader_Cache
horde-Horde_Argv-DEPEND=	${PEARDIR}/Horde/Argv/Parser.php:devel/pear-Horde_Argv
horde-Horde_Browser-DEPEND=	${PEARDIR}/Horde/Browser.php:www/pear-Horde_Browser
horde-Horde_Cache-DEPEND=	${PEARDIR}/Horde/Cache.php:devel/pear-Horde_Cache
horde-Horde_Cli-DEPEND=		${PEARDIR}/Horde/Cli.php:devel/pear-Horde_Cli
horde-Horde_Compress-DEPEND=	${PEARDIR}/Horde/Compress.php:archivers/pear-Horde_Compress
horde-Horde_Compress_Fast-DEPEND=	${PEARDIR}/Horde/Compress/Fast.php:archivers/pear-Horde_Compress_Fast
horde-Horde_Constraint-DEPEND=	${PEARDIR}/Horde/Constraint.php:devel/pear-Horde_Constraint
horde-Horde_Controller-DEPEND=	${PEARDIR}/Horde/Controller.php:devel/pear-Horde_Controller
horde-Horde_Core-DEPEND=	${PEARDIR}/Horde.php:devel/pear-Horde_Core
horde-Horde_Crypt-DEPEND=	${PEARDIR}/Horde/Crypt.php:security/pear-Horde_Crypt
horde-Horde_Crypt_Blowfish-DEPEND=	${PEARDIR}/Horde/Crypt/Blowfish.php:security/pear-Horde_Crypt_Blowfish
horde-Horde_CssMinify-DEPEND=	${PEARDIR}/Horde/CssMinify.php:textproc/pear-Horde_CssMinify
horde-Horde_Css_Parser-DEPEND=	${PEARDIR}/Horde/Css/Parser.php:www/pear-Horde_Css_Parser
horde-Horde_Data-DEPEND=	${PEARDIR}/Horde/Data.php:devel/pear-Horde_Data
horde-Horde_Date-DEPEND=	${PEARDIR}/Horde/Date.php:devel/pear-Horde_Date
horde-Horde_Date_Parser-DEPEND=	${PEARDIR}/Horde/Date/Parser.php:devel/pear-Horde_Date_Parser
horde-Horde_Dav-DEPEND=		${PEARDIR}/Horde/Dav/Client.php:www/pear-Horde_Dav
horde-Horde_Db-DEPEND=		${PEARDIR}/Horde/Db.php:databases/pear-Horde_Db
horde-Horde_Editor-DEPEND=	${PEARDIR}/Horde/Editor.php:www/pear-Horde_Editor
horde-Horde_Exception-DEPEND=	${PEARDIR}/Horde/Exception.php:devel/pear-Horde_Exception	
horde-Horde_Feed-DEPEND=	${PEARDIR}/Horde/Feed.php:www/pear-Horde_Feed
horde-Horde_Form-DEPEND=	${PEARDIR}/Horde/Form.php:www/pear-Horde_Form
horde-Horde_Group-DEPEND=	${PEARDIR}/Horde/Group/Base.php:security/pear-Horde_Group
horde-Horde_HashTable-DEPEND=	${PEARDIR}/Horde/HashTable/Base.php:databases/pear-Horde_HashTable
horde-Horde_History-DEPEND=	${PEARDIR}/Horde/History.php:devel/pear-Horde_History
horde-Horde_Http-DEPEND=	${PEARDIR}/Horde/Http.php:www/pear-Horde_Http
horde-Horde_Icalendar-DEPEND=	${PEARDIR}/Horde/Icalendar.php:devel/pear-Horde_Icalendar
horde-Horde_Idna-DEPEND=	${PEARDIR}/Horde/Idna.php:dns/pear-Horde_Idna
horde-Horde_Image-DEPEND=	${PEARDIR}/Horde/Image.php:graphics/pear-Horde_Image
horde-Horde_Imap_Client-DEPEND=	${PEARDIR}/Horde/Imap/Client.php:mail/pear-Horde_Imap_Client
horde-Horde_Imsp-DEPEND=	${PEARDIR}/Horde/Imsp.php:databases/pear-Horde_Imsp
horde-Horde_Itip-DEPEND=	${PEARDIR}/Horde/Itip.php:devel/pear-Horde_Itip
horde-Horde_Injector-DEPEND=	${PEARDIR}/Horde/Injector.php:devel/pear-Horde_Injector
horde-Horde_JavascriptMinify-DEPEND=	${PEARDIR}/Horde/JavascriptMinify.php:textproc/pear-Horde_JavascriptMinify
horde-Horde_Kolab_Format-DEPEND=	${PEARDIR}/Horde/Kolab/Format.php:textproc/pear-Horde_Kolab_Format
horde-Horde_Kolab_Server-DEPEND=	${PEARDIR}/Horde/Kolab/Server/Factory.php:net/pear-Horde_Kolab_Server
horde-Horde_Kolab_Session-DEPEND=	${PEARDIR}/Horde/Kolab/Session.php:net/pear-Horde_Kolab_Session
horde-Horde_Kolab_Storage-DEPEND=	${PEARDIR}/Horde/Kolab/Storage.php:mail/pear-Horde_Kolab_Storage
horde-Horde_Ldap-DEPEND=	${PEARDIR}/Horde/Ldap.php:net/pear-Horde_Ldap
horde-Horde_ListHeaders-DEPEND=	${PEARDIR}/Horde/ListHeaders.php:mail/pear-Horde_ListHeaders
horde-Horde_Lock-DEPEND=	${PEARDIR}/Horde/Lock.php:devel/pear-Horde_Lock
horde-Horde_Log-DEPEND=		${PEARDIR}/Horde/Log.php:sysutils/pear-Horde_Log
horde-Horde_LoginTasks-DEPEND=	${PEARDIR}/Horde/LoginTasks.php:devel/pear-Horde_LoginTasks
horde-Horde_Mail-DEPEND=	${PEARDIR}/Horde/Mail/Transport.php:mail/pear-Horde_Mail
horde-Horde_Mail_Autoconfig-DEPEND=	${PEARDIR}/Horde/Mail/Autoconfig.php:mail/pear-Horde_Mail_Autoconfig
horde-Horde_Mapi-DEPEND=	${PEARDIR}/Horde/Mapi.php:mail/pear-Horde_Mapi
horde-Horde_Memcache-DEPEND=	${PEARDIR}/Horde/Memcache.php:databases/pear-Horde_Memcache
horde-Horde_Mime-DEPEND=	${PEARDIR}/Horde/Mime.php:mail/pear-Horde_Mime
horde-Horde_Mime_Viewer-DEPEND=	${PEARDIR}/Horde/Mime/Viewer.php:mail/pear-Horde_Mime_Viewer
horde-Horde_Mongo-DEPEND=	${PEARDIR}/Horde/Mongo/Client.php:databases/pear-Horde_Mongo
horde-Horde_Nls-DEPEND=		${PEARDIR}/Horde/Nls.php:devel/pear-Horde_Nls
horde-Horde_Notification-DEPEND=	${PEARDIR}/Horde/Notification.php:devel/pear-Horde_Notification
horde-Horde_Oauth-DEPEND=	${PEARDIR}/Horde/Oauth/Consumer.php:security/pear-Horde_Oauth
horde-Horde_Pack-DEPEND=	${PEARDIR}/Horde/Pack.php:archivers/pear-Horde_Pack
horde-Horde_Pdf-DEPEND=		${PEARDIR}/Horde/Pdf/Writer.php:textproc/pear-Horde_Pdf
horde-Horde_Perms-DEPEND=	${PEARDIR}/Horde/Perms.php:security/pear-Horde_Perms
horde-Horde_Prefs-DEPEND=	${PEARDIR}/Horde/Prefs.php:devel/pear-Horde_Prefs
horde-Horde_Queue-DEPEND=	${PEARDIR}/Horde/Queue/Runner.php:devel/pear-Horde_Queue
horde-Horde_Rdo-DEPEND=		${PEARDIR}/Horde/Rdo.php:devel/pear-Horde_Rdo
horde-Horde_Role-DEPEND=	${PEARDIR}/PEAR/Installer/Role/Horde/Role.php:devel/pear-Horde_Role
horde-Horde_Rpc-DEPEND=		${PEARDIR}/Horde/Rpc.php:net/pear-Horde_Rpc
horde-Horde_Routes-DEPEND=	${PEARDIR}/Horde/Routes/Route.php:www/pear-Horde_Routes
horde-Horde_Secret-DEPEND=	${PEARDIR}/Horde/Secret.php:security/pear-Horde_Secret
horde-Horde_Serialize-DEPEND=	${PEARDIR}/Horde/Serialize.php:devel/pear-Horde_Serialize
horde-Horde_SessionHandler-DEPEND=	${PEARDIR}/Horde/SessionHandler.php:www/pear-Horde_SessionHandler
horde-Horde_Scheduler-DEPEND=	${PEARDIR}/Horde/Scheduler.php:devel/pear-Horde_Scheduler
horde-Horde_Scribe-DEPEND=	${PEARDIR}/Horde/Scribe.php:net/pear-Horde_Scribe
horde-Horde_Share-DEPEND=	${PEARDIR}/Horde/Share/Base.php:security/pear-Horde_Share
horde-Horde_Smtp-DEPEND=	${PEARDIR}/Horde/Smtp.php:mail/pear-Horde_Smtp
horde-Horde_Socket_Client-DEPEND=	${PEARDIR}/Horde/Socket/Client.php:net/pear-Horde_Socket_Client
horde-Horde_SpellChecker-DEPEND=	${PEARDIR}/Horde/SpellChecker.php:textproc/pear-Horde_SpellChecker
horde-Horde_Stream-DEPEND=	${PEARDIR}/Horde/Stream.php:devel/pear-Horde_Stream
horde-Horde_Stream_Filter-DEPEND=	${PEARDIR}/Horde/Stream/Filter/Crc32.php:devel/pear-Horde_Stream_Filter
horde-Horde_Stream_Wrapper-DEPEND=	${PEARDIR}/Horde/Stream/Wrapper/StringStream.php:devel/pear-Horde_Stream_Wrapper
horde-Horde_Service_Facebook-DEPEND=	${PEARDIR}/Horde/Service/Facebook.php:www/pear-Horde_Service_Facebook
horde-Horde_Service_Twitter-DEPEND=	${PEARDIR}/Horde/Service/Twitter.php:www/pear-Horde_Service_Twitter
horde-Horde_Service_UrlShortener-DEPEND=	${PEARDIR}/Horde/Service/UrlShortener.php:www/pear-Horde_Service_UrlShortener
horde-Horde_Service_Weather-DEPEND=	${PEARDIR}/Horde/Service/Weather.php:www/pear-Horde_Service_Weather
horde-Horde_Support-DEPEND=	${PEARDIR}/Horde/Support/Array.php:devel/pear-Horde_Support
horde-Horde_SyncMl-DEPEND=	${PEARDIR}/Horde/SyncMl.php:comms/pear-Horde_SyncMl
horde-Horde_Url-DEPEND=		${PEARDIR}/Horde/Url.php:net/pear-Horde_Url	
horde-Horde_Util-DEPEND=	${PEARDIR}/Horde/Util.php:devel/pear-Horde_Util	
horde-Horde_Template-DEPEND=	${PEARDIR}/Horde/Template.php:www/pear-Horde_Template
horde-Horde_Text_Diff-DEPEND=	${PEARDIR}/Horde/Text/Diff.php:textproc/pear-Horde_Text_Diff
horde-Horde_Text_Filter-DEPEND=	${PEARDIR}/Horde/Text/Filter.php:textproc/pear-Horde_Text_Filter
horde-Horde_Text_Filter_Csstidy-DEPEND=	${PEARDIR}/Horde/Text/Filter/Csstidy.php:textproc/pear-Horde_Text_Filter_Csstidy
horde-Horde_Text_Flowed-DEPEND=	${PEARDIR}/Horde/Text/Flowed.php:textproc/pear-Horde_Text_Flowed
horde-Horde_Thrift-DEPEND=	${PEARDIR}/Horde/Thrift.php:devel/pear-Horde_Thrift
horde-Horde_Timezone-DEPEND=	${PEARDIR}/Horde/Timezone.php:devel/pear-Horde_Timezone
horde-Horde_Token-DEPEND=	${PEARDIR}/Horde/Token.php:devel/pear-Horde_Token
horde-Horde_Translation-DEPEND=	${PEARDIR}/Horde/Translation.php:devel/pear-Horde_Translation
horde-Horde_Tree-DEPEND=	${PEARDIR}/Horde/Tree.php:devel/pear-Horde_Tree
horde-Horde_Vfs-DEPEND=		${PEARDIR}/Horde/Vfs.php:sysutils/pear-Horde_Vfs
horde-Horde_View-DEPEND=	${PEARDIR}/Horde/View.php:devel/pear-Horde_View
horde-Horde_Xml_Element-DEPEND=	${PEARDIR}/Horde/Xml/Element.php:textproc/pear-Horde_Xml_Element
horde-Horde_Xml_Wbxml-DEPEND=	${PEARDIR}/Horde/Xml/Wbxml.php:textproc/pear-Horde_Xml_Wbxml
horde-content-DEPEND=		${LOCALBASE}/${HORDE_DIR}/content/lib/Tagger.php:devel/horde-content
horde-gollem-DEPEND=		${LOCALBASE}/${HORDE_DIR}/gollem/index.php:ftp/horde-gollem
horde-horde-DEPEND=		${LOCALBASE}/${HORDE_DIR}/index.php:www/horde-base
horde-imp-DEPEND=		${LOCALBASE}/${HORDE_DIR}/imp/index.php:mail/horde-imp
horde-ingo-DEPEND=		${LOCALBASE}/${HORDE_DIR}/ingo/index.php:mail/horde-ingo
horde-kronolith-DEPEND=		${LOCALBASE}/${HORDE_DIR}/kronolith/index.php:deskutils/horde-kronolith
horde-mnemo-DEPEND=		${LOCALBASE}/${HORDE_DIR}/mnemo/index.php:deskutils/horde-mnemo
horde-nag-DEPEND=		${LOCALBASE}/${HORDE_DIR}/nag/index.php:deskutils/horde-nag
horde-timeobjects-DEPEND=	${LOCALBASE}/${HORDE_DIR}/timeobjects/lib/Driver.php:devel/horde-timeobjects
horde-trean-DEPEND=		${LOCALBASE}/${HORDE_DIR}/trean/index.php:www/horde-trean
horde-turba-DEPEND=		${LOCALBASE}/${HORDE_DIR}/turba/index.php:mail/horde-turba

.if defined(USE_HORDE_RUN)
. for DEP in ${USE_HORDE_RUN}
.  if !defined(horde-${DEP}-DEPEND)
UNKNOWN_HORDE_PACKAGES+=	${DEP}
.  else
RUN_DEPENDS+=	${horde-${DEP}-DEPEND}@${PHP_FLAVOR}
.  endif
. endfor
.endif

.if defined(USE_HORDE_BUILD)
. for DEP in ${USE_HORDE_BUILD}
.  if !defined(horde-${DEP}-DEPEND)
UNKNOWN_HORDE_PACKAGES+=	${DEP}
.  else
BUILD_DEPENDS+=	${horde-${DEP}-DEPEND}@${PHP_FLAVOR}
.  endif
. endfor
.endif

.if defined(UNKNOWN_HORDE_PACKAGES)
IGNORE=	unknown Horde package(s): ${UNKNOWN_HORDE_PACKAGES}
.endif

.include "${USESDIR}/pear.mk"
.endif
