# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	todo
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.defora.org/os/download/download/3506/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Todo-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop todo list

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop

USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

.include <bsd.port.mk>
