# Created by: Mark Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ufraw
PORTVERSION=	0.22
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Read and manipulate raw images from various digital cameras

LICENSE=	GPLv2

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		liblcms2.so:graphics/lcms2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --enable-extras
USES=		desktop-file-utils gettext gmake jpeg pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
PC_FALSE=	cinepaint

OPTIONS_DEFINE=	CONTRAST DST EXIV2 LENSFUN FITS GIMP GTK2 GNOME
OPTIONS_DEFAULT=CONTRAST EXIV2 LENSFUN GTK2

CONTRAST_DESC=	Enable contrast setting option
DST_DESC=	Use local time for timestamps
FITS_DESC=	FITS output support
GIMP_DESC=	Install GIMP plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONTRAST}
CONFIGURE_ARGS+=	--enable-contrast
.endif

.if ${PORT_OPTIONS:MDST}
CONFIGURE_ARGS+=	--enable-dst-correction
.endif

.if ${PORT_OPTIONS:MEXIV2}
LIB_DEPENDS+=	libexiv2.so:graphics/exiv2
.else
PC_FALSE+=	exiv2
.endif

.if ${PORT_OPTIONS:MLENSFUN}
LIB_DEPENDS+=	liblensfun.so:graphics/lensfun
.else
PC_FALSE+=	lensfun
.endif

.if ${PORT_OPTIONS:MFITS}
LIB_DEPENDS+=	libcfitsio.so:astro/cfitsio
.else
PC_FALSE+=	cfitsio
.endif

.if ${PORT_OPTIONS:MGIMP}
LIB_DEPENDS+=	libgimp-2.0.so:graphics/gimp-app
PLIST_SUB+=	GIMP=""
.else
CONFIGURE_ARGS+=--without-gimp
PC_FALSE+=	gimp
PLIST_SUB+=	GIMP="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=	libgtkimageview.so:x11-toolkits/gtkimageview
PLIST_SUB+=	MGTK2=""
.else
PLIST_SUB+=	MGTK2="@comment "
CONFIGURE_ARGS+=--without-gtk
.endif

.if ${PORT_OPTIONS:MGNOME}
CATEGORIES+=	gnome
USE_GNOME=	gconf2
CONFIGURE_ARGS+=	--enable-mime
GCONF_SCHEMAS=	${PORTNAME}.schemas
.endif

post-patch:
	@${REINPLACE_CMD} -e '18s|^$$|#include <sys/types.h>|' \
		${WRKSRC}/dcraw.h
# Fix GConf2 schemas installation path; unconditionalize installation of
# .desktop file; avoid conflict with `graphics/dcraw' (rename the binary)
	@${REINPLACE_CMD} -e '/@schemasdir/s|datadir|sysconfdir| ; \
		/@app/s|@INSTALL_MIME_TRUE@|| ; \
		s|dcraw\$$(EXEEXT)|${PORTNAME}-&|' ${WRKSRC}/Makefile.in
.for i in ${PC_FALSE}
	@${REINPLACE_CMD} -e '/PKG_CONFIG.*${i}/s|$$PKG_CONFIG|${FALSE}|' \
		${WRKSRC}/configure
.endfor

.include <bsd.port.mk>
