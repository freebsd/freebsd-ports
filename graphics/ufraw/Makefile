# Created by: Mark Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ufraw
PORTVERSION=	0.19.2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Read and manipulate raw images from various digital cameras

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png \
		lcms:${PORTSDIR}/graphics/lcms

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --enable-extras
USES=		gettext
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
PC_FALSE=	cinepaint

MAN1=		ufraw.1

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
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
.else
PC_FALSE+=	exiv2
.endif

.if ${PORT_OPTIONS:MLENSFUN}
LIB_DEPENDS+=	lensfun:${PORTSDIR}/graphics/lensfun
.else
PC_FALSE+=	lensfun
.endif

.if ${PORT_OPTIONS:MFITS}
LIB_DEPENDS+=	cfitsio:${PORTSDIR}/astro/cfitsio
.else
PC_FALSE+=	cfitsio
.endif

.if ${PORT_OPTIONS:MGIMP}
LIB_DEPENDS+=	gimp-2.0:${PORTSDIR}/graphics/gimp-app
PLIST_SUB+=	GIMP=""
.else
CONFIGURE_ARGS+=--without-gimp
PC_FALSE+=	gimp
PLIST_SUB+=	GIMP="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=	gtkimageview:${PORTSDIR}/x11-toolkits/gtkimageview
PLIST_SUB+=	MGTK2=""
.else
PLIST_SUB+=	MGTK2="@comment "
CONFIGURE_ARGS+=--without-gtk
.endif

.if ${PORT_OPTIONS:MGNOME}
CATEGORIES+=	gnome
USE_GNOME=	desktopfileutils gconf2
CONFIGURE_ARGS+=	--enable-mime
GCONF_SCHEMAS=	${PORTNAME}.schemas
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
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

pre-build:
	@${INSTALL_SCRIPT} ${LOCALBASE}/share/icu/50.1.2/mkinstalldirs \
		${WRKSRC}

post-install:
.if ${PORT_OPTIONS:MGNOME}
	@${SETENV} GCONF_CONFIG_SOURCE=${GCONF_CONFIG_SOURCE} \
		gconftool-2 --makefile-install-rule \
		${PREFIX}/etc/gconf/schemas/${PORTNAME}.schemas
	@-update-desktop-database
.endif

.include <bsd.port.mk>
