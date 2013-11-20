# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-image-viewer
PORTVERSION=	1.6.1
CATEGORIES=	graphics mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye of MATE image viewer

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info
USE_XZ=		yes
USE_MATE=	desktop docutils icontheme
USE_XORG=	x11
USE_GNOME=	gdkpixbuf2 glib20 gnomehier gtk20 librsvg2 libxml2
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		--disable-python \
		--without-cms
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.eom.gschema.xml

OPTIONS_DEFINE=	EXIF EXEMPI
OPTIONS_DEFAULT=EXIF EXEMPI
EXIF_DESC=	Digital camera file meta-data support
EXEMPI_DESC=	XMP support

.include <bsd.port.options.mk>

_WITH_EXIF=	no
_WITH_EXEMPI=	no

.if ${PORT_OPTIONS:MEXIF}
CONFIGURE_ARGS+=--with-libexif
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
_WITH_EXIF=	yes
.else
CONFIGURE_ARGS+=--without-libexif
PLIST_SUB+=	EXIF="@comment "
.endif

.if ${PORT_OPTIONS:MEXEMPI}
CONFIGURE_ARGS+=--with-xmp
LIB_DEPENDS+=	libexempi.so:${PORTSDIR}/textproc/exempi
_WITH_EXEMPI=	yes
.else
CONFIGURE_ARGS+=--without-xmp
.endif

.if ${_WITH_EXIF}=="yes" || ${_WITH_EXEMPI}=="yes"
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/eom/plugins/*.so

.include <bsd.port.mk>
