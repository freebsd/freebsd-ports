# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	editor
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.defora.org/os/download/download/3702/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Editor-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop text editor

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop

MAKE_ARGS=	PREFIX=${PREFIX}
USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtk20

.include <bsd.port.mk>
