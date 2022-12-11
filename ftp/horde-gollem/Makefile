PORTNAME=	gollem
PORTVERSION=	3.0.13
CATEGORIES=	ftp www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Web-based File Manager
WWW=		https://www.horde.org/apps/gollem/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_WITH_PHP=80 81 82

USES=		horde php cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Cache \
		Horde_Core \
		Horde_Editor \
		Horde_Exception \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Perms \
		Horde_Secret \
		Horde_Serialize \
		Horde_Support \
		Horde_Url \
		Horde_Util \
		Horde_Vfs \
		Horde_View
# Optional but we want it
USE_HORDE_RUN+=	Horde_Db \
		Horde_Share
USE_PHP=	gettext json

.include <bsd.port.mk>
