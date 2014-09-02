# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/editors/gedit/Makefile,v 1.125 2010/09/30 19:58:54 kwm Exp $

PORTNAME=	gedit
PORTVERSION=	2.30.4
PORTREVISION=	4
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GNOME 2 Desktop Environment

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USES=		desktop-file-utils gettext gmake libtool:keepla  pathfix \
		pkgconfig tar:bzip2
USE_XORG=	ice sm
INSTALLS_OMF=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix intlhack gconf2 gtksourceview2 gnomedocutils
GNU_CONFIGURE=	yes
GNOME_DESKTOP_VERSION=2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION="2.20"

GCONF_SCHEMAS=	gedit.schemas gedit-file-browser.schemas

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_CONFIGURE_ENABLE=python
PYTHON_USE=		GNOME=pygtksourceview

post-patch:
	@${REINPLACE_CMD} '/^libgedit_la_LIBADD =/s/=/= -lgmodule-2.0/' \
		${WRKSRC}/gedit/Makefile.in
	@${REINPLACE_CMD} '/EGG_SMCLIENT_LIBS =/s/$$/ -lICE/' \
		${WRKSRC}/gedit/smclient/Makefile.in

.include <bsd.port.mk>
