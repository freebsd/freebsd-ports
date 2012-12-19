# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	phone
PORTVERSION=	0.3.10
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/3707/
DISTNAME=	Phone-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS telephony application

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop \
		pulse:${PORTSDIR}/audio/pulseaudio \
		purple:${PORTSDIR}/net-im/libpurple \
		sofia-sip-ua:${PORTSDIR}/net/sofia-sip
BUILD_DEPENDS=	locker:${PORTSDIR}/x11/deforaos-locker \
		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
