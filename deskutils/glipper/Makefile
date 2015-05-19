# Created by: Yuri Pankov <yuri.pankov@gmail.com>
# $FreeBSD$

PORTNAME=	glipper
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clipboard manager for the GNOME panel

BROKEN=		Uses unknown GNOME components pygnomedesktop and pygnomeextras
DEPRECATED=	Broken since update to gnome3
EXPIRATION_DATE=	2015-06-02

USES=		gettext gmake iconv libtool pathfix pkgconfig python tar:bzip2
USE_GNOME=	gnomeprefix intltool pygnomedesktop pygnomeextras
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec --disable-schemas-install
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GCONF_SCHEMAS=	glipper.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gtypes.h|glib.h|g' \
		${WRKSRC}/glipper/keybinder/tomboykeybinder.h

.include <bsd.port.mk>
