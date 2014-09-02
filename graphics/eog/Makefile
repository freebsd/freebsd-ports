# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/eog/Makefile,v 1.123 2010/11/16 10:11:41 kwm Exp $

PORTNAME=	eog
PORTVERSION=	2.32.1
PORTREVISION=	6
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The Eye Of Gnome image viewer

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USES=		desktop-file-utils gettext gmake libtool:keepla pathfix \
		pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack librsvg2 gconf2 gnomedesktop
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
GNOME_DESKTOP_VERSION=2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	eog.schemas

.include <bsd.port.pre.mk>

_WITH_EXIF=	no
_WITH_EXEMPI=	no

.if !defined(WITHOUT_EXIF) || (exists(${LOCALBASE}/lib/libexif.so.12) || \
	defined(WITH_EXIF))
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
_WITH_EXIF=	yes
.else
PLIST_SUB+=	EXIF="@comment "
.endif

.if !defined(WITHOUT_EXEMPI) || (exists(${LOCALBASE}/lib/libexempi.so)) || \
    	defined(WITH_EXEMPI)
LIB_DEPENDS+=	libexempi.so:${PORTSDIR}/textproc/exempi
_WITH_EXEMPI=	yes
.endif

.if ${_WITH_EXIF}=="yes" || ${_WITH_EXEMPI}=="yes"
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

.if ${HAVE_GNOME:Mpygtk2}!=""
USE_GNOME+=	pygtk2
CONFIGURE_ARGS+=--enable-python
.else
CONFIGURE_ARGS+=--disable-python
.endif

post-patch:
	@${REINPLACE_CMD} '/^EOG_MODULES=/s/"/"gmodule-2.0 /' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
