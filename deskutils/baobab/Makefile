# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	baobab
PORTVERSION=	3.18.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 graphical directory tree analyzer

BUILD_DEPENDS=	itstool:textproc/itstool \
		vapigen:lang/vala
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop

CONFLICTS=	gnome-utils-2.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack libxml2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.baobab.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|MimeType=inode/directory;|MimeType=|g' \
		${WRKSRC}/data/org.gnome.baobab.desktop.in.in

.include <bsd.port.mk>
