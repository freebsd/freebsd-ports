# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	todo
PORTVERSION=	0.1.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.defora.org/os/download/download/3506/
DISTNAME=	Todo-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop todo list

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
