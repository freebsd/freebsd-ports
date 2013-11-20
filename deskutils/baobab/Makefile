# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/baobab/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	baobab
PORTVERSION=	3.6.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 graphical directory tree analyzer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop

CONFLICTS=	gnome-utils-2.[0-9]*

NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack libxml2 gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		baobab.1
GLIB_SCHEMAS=	org.gnome.baobab.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-but-set-variable||g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
