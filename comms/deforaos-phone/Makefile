# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phone
PORTVERSION=	0.3.12
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/4296/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Phone-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS telephony application

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libpulse.so:audio/pulseaudio \
		libpurple.so:net-im/libpurple \
		libsofia-sip-ua.so:net/sofia-sip
BUILD_DEPENDS=	locker:x11/deforaos-locker \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-patch:
	@${REINPLACE_CMD} -e 's,/dev/modem,/dev/cuaU0,g' \
		${WRKSRC}/src/modems/hayes.c

.include <bsd.port.mk>
