# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	phone
PORTVERSION=	0.3.11
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/3721/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Phone-${PORTVERSION}

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

USES=		pkgconfig gettext
USE_GNOME=	gtk20 desktopfileutils
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,/dev/modem,/dev/cuaU0,g' \
		${WRKSRC}/src/modems/hayes.c

.include <bsd.port.mk>
