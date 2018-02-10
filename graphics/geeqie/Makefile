# Created by: Martin Tournoij <carpetsmoker@rwxrwxrwx.net>
# $FreeBSD$

PORTNAME=	geeqie
PORTVERSION=	1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.geeqie.org/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		autoreconf gettext gmake jpeg localbase pkgconfig \
		desktop-file-utils tar:xz lua:51
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readmedir="${DOCSDIR}"

PORTDOCS=	*

OPTIONS_DEFINE=	EXIV2 LCMS LIRC GPS TIFF DOCS
OPTIONS_DEFAULT=EXIV2 LCMS GTK2
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=GTK2 GTK3

EXIV2_DESC=	Metadata editing
LCMS_DESC=	Color adjusting
LIRC_DESC=	Remote control
GPS_DESC=	GPS map support via libchamplain (experimental!)
TOOLKIT_DESC=	Graphical user interface toolkit
GTK2_DESC=	Use GTK 2
GTK3_DESC=	Use GTK 3

EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_CONFIGURE_ENABLE=	exiv2

LCMS_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS_CONFIGURE_ENABLE=	lcms

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc
LIRC_CONFIGURE_ON=	--with-lirc-prefix="${LOCALBASE}"

GPS_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
			libclutter-gtk-1.0.so:graphics/clutter-gtk3
GPS_CONFIGURE_ENABLE=	map gpu-accell

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ENABLE=	tiff

GTK2_USE=		GNOME=gtk20
GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_PREVENTS=		GPS
GTK3_PREVENTS_MSG=	GPS option does not support GTK3 yet

post-patch:
	@${REINPLACE_CMD} -e 's| -r %F||' ${WRKSRC}/geeqie.desktop.in
	@${REINPLACE_CMD} -e '/readme_DATA/ s|COPYING||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|lua5.1|lua-5.1|' ${WRKSRC}/configure.in
# I cannot get gnome-doc-tool working properly: Outputs gibberish
	@${REINPLACE_CMD} -Ee '/^(SUBDIRS|DIST_SUBDIRS)/ s|doc||' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
