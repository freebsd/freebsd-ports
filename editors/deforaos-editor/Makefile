# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	editor
PORTVERSION=	0.2.1
CATEGORIES=	editors
MASTER_SITES=	http://www.defora.org/os/download/download/3702/
DISTNAME=	Editor-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop text editor

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes

.include <bsd.port.mk>
