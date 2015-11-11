# Created by: Martin Matuska (mm@FreeBSD.org)
# $FreeBSD$

PORTNAME=	gollem
PORTVERSION=	3.0.6
CATEGORIES=	ftp www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Web-based File Manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	horde cpe
USE_PHP=	gettext json
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

.include <bsd.port.mk>
