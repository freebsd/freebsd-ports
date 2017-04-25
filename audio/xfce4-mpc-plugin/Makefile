# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-mpc-plugin
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Musicpd client plugin for the Xfce panel

LICENSE=	ISCL

LIB_DEPENDS=	libmpd.so:audio/libmpd
RUN_DEPENDS=	musicpd:audio/musicpd

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	gtk30 intltool cairo gdkpixbuf2
USE_XFCE=	panel

CONFIGURE_ARGS+=	--with-libmpd=${LOCALBASE}

.include <bsd.port.mk>
