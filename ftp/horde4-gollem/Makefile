# Ports collection makefile for:  horde4-gollem
# Date created:			  Oct 11, 2011
# Whom:				  Martin Matuska (mm@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	gollem
DISTVERSION=	2.0.0RC2
CATEGORIES=	ftp www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Web-based File Manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	horde4-${PORTNAME}

USE_PHP=	gettext json
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Browser \
		Horde_Cache \
		Horde_Core \
		Horde_Db \
		Horde_Editor \
		Horde_Exception \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Notification \
		Horde_Perms \
		Horde_Secret \
		Horde_Serialize \
		Horde_Support \
		Horde_Url \
		Horde_Util \
		Horde_Vfs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
