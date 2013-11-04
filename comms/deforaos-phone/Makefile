# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	phone
PORTVERSION=	0.3.12
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/4296/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Phone-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS telephony application

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libpurple.so:${PORTSDIR}/net-im/libpurple \
		libsofia-sip-ua.so:${PORTSDIR}/net/sofia-sip
BUILD_DEPENDS=	locker:${PORTSDIR}/x11/deforaos-locker \
		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-patch:
	@${REINPLACE_CMD} -e 's,/dev/modem,/dev/cuaU0,g' \
		${WRKSRC}/src/modems/hayes.c

.include <bsd.port.mk>
