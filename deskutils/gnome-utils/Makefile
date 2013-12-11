# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/deskutils/gnome-utils/Makefile,v 1.159 2012/09/01 23:02:09 mezz Exp $

PORTNAME=	gnome-utils
PORTVERSION=	2.32.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 support utilities

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

CONFLICTS=	baobob-3.[0-9]* gnome-dictionary-3.[0-9]* \
		gnome-font-viewer-3.[0-9]* gnome-screenshot-3.[0-9]* \
		gnome-search-tool-3.[0-9]* gnome-system-log-3.[0-9]*

USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel ltverhack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-maintainer-flags=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-dictionary.1 gnome-screenshot.1 gnome-search-tool.1 \
		gnome-system-log.1 baobab.1
GCONF_SCHEMAS=	gnome-dictionary.schemas gnome-screenshot.schemas \
		gnome-search-tool.schemas baobab.schemas \
		gnome-system-log.schemas

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/gsearchtool/libgnomeui-deprecated/Makefile.in
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/gnome-dictionary/libgdict/Makefile.in \
		${WRKSRC}/gsearchtool/Makefile.in \
		${WRKSRC}/gsearchtool/libgnomeui-deprecated/Makefile.in \
		${WRKSRC}/libeggsmclient/Makefile.in

.include <bsd.port.mk>
