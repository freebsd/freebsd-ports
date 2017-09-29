# $FreeBSD$

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.8.1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for the Xfce panel

LICENSE=	GPLv2

LIB_DEPENDS=	libxklavier.so:x11/libxklavier

USES=		gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 intltool librsvg2 libwnck3 cairo
USE_XFCE=	panel
USE_XORG=	x11
INSTALL_TARGET=	install-strip

# Downgrade libxklavier
post-patch:
	@${REINPLACE_CMD} -e 's|5.4|5.3|g' ${WRKSRC}/configure

.include <bsd.port.mk>
