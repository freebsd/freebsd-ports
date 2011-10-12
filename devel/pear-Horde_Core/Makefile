# Ports collection makefile for:  pear-Horde_Date
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Core
PORTVERSION=	1.6.0
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Core Framework libraries

CONFLICTS=	horde-3*

OPTIONS=	KOLAB "Enable Kolab server support" Off \
		LZF "Depend on lzf PHP extension" Off \
		SOCKETS "Depend on sockets PHP extension" Off

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
		Horde_Controller \
		Horde_Data \
		Horde_Date \
		Horde_Exception \
		Horde_Group \
		Horde_History \
		Horde_Injector \
		Horde_Lock \
		Horde_Log \
		Horde_LoginTasks \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Notification \
		Horde_Perms \
		Horde_Prefs \
		Horde_Secret \
		Horde_Serialize \
		Horde_SessionHandler \
		Horde_Share \
		Horde_Support \
		Horde_Template \
		Horde_Token \
		Horde_Text_Filter \
		Horde_Text_Filter_Csstidy \
		Horde_Translation \
		Horde_Url \
		Horde_Util \
		Horde_View

# Not required but wanted
USE_HORDE_RUN+=	Horde_Routes

.include <bsd.port.pre.mk>

.if defined(WITH_KOLAB)
USE_HORDE_RUN+=	Horde_Kolab_Server \
		Horde_Kolab_Session \
		Horde_Kolab_Storage
.endif

.if defined(WITH_LZF)
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/lzf.so:${PORTSDIR}/archivers/pecl-lzf
.endif

.if defined(WITH_SOCKETS)
USE_PHP+=	sockets
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
