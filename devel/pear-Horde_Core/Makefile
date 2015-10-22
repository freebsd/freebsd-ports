# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Horde_Core
PORTVERSION=	2.22.1
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Core Framework libraries

CONFLICTS=	horde-3*

OPTIONS_DEFINE=	KOLAB LZF SOCKETS
KOLAB_DESC=	Enable Kolab server support
LZF_DESC=	Depend on lzf PHP extension
SOCKETS_DESC=	Depend on sockets PHP extension

USES=	horde
USE_PHP=	session

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

KOLAB_USE=	HORDE_RUN=Horde_Kolab_Server,Horde_Kolab_Session,Horde_Kolab_Storage
LZF_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/lzf.so:${PORTSDIR}/archivers/pecl-lzf
SOCKETS_USE=	PHP=sockets

.include <bsd.port.mk>
