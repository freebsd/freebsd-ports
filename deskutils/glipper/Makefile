# Created by: Yuri Pankov <yuri.pankov@gmail.com>
# $FreeBSD$

PORTNAME=	glipper
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clipboard manager for the GNOME panel

USES=		gettext gmake iconv libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intltool pygnomedesktop pygnomeextras
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec --disable-schemas-install

GCONF_SCHEMAS=	glipper.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gtypes.h|glib.h|g' \
		${WRKSRC}/glipper/keybinder/tomboykeybinder.h

.include <bsd.port.mk>
