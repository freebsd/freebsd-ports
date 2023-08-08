PORTNAME=	Horde_Core
DISTVERSION=	2.31.18
CATEGORIES=	devel www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Core Framework libraries
WWW=		https://pear.horde.org

LICENSE=	LGPL21

USES=		horde php cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_ActiveSync \
		Horde_Alarm \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Browser \
		Horde_Cache \
		Horde_Cli \
		Horde_Compress \
		Horde_Compress_Fast \
		Horde_Controller \
		Horde_Css_Parser \
		Horde_CssMinify \
		Horde_Data \
		Horde_Date \
		Horde_Exception \
		Horde_Group \
		Horde_History \
		Horde_Injector \
		Horde_JavascriptMinify \
		Horde_Lock \
		Horde_Log \
		Horde_LoginTasks \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Notification \
		Horde_Pack \
		Horde_Perms \
		Horde_Prefs \
		Horde_Secret \
		Horde_Serialize \
		Horde_SessionHandler \
		Horde_Share \
		Horde_Smtp \
		Horde_Support \
		Horde_Template \
		Horde_Token \
		Horde_Text_Filter \
		Horde_Translation \
		Horde_Url \
		Horde_Util \
		Horde_View
# Not required but wanted
USE_HORDE_RUN+=	Horde_Routes
USE_PHP=	session

CONFLICTS=	horde-3*

NO_ARCH=	yes

OPTIONS_DEFINE=	KOLAB LZF SOCKETS
KOLAB_DESC=	Enable Kolab server support
LZF_DESC=	Depend on lzf PHP extension
SOCKETS_DESC=	Depend on sockets PHP extension

KOLAB_USE=	HORDE_RUN=Horde_Kolab_Server,Horde_Kolab_Session,Horde_Kolab_Storage
LZF_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/lzf.so:archivers/pecl-lzf@${PHP_FLAVOR}
SOCKETS_USE=	PHP=sockets

.include <bsd.port.mk>
