# New ports collection makefile for:	UFRaw
# Date created:				Sun 10 Apr 2005 14:44:15 BST
# Whom:					Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ufraw
PORTVERSION=	0.18
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Read and manipulate raw images from various digital cameras

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png15:${PORTSDIR}/graphics/png \
		lcms.1:${PORTSDIR}/graphics/lcms

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --enable-extras
USE_GETTEXT=	yes
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
PC_FALSE=	cinepaint

MAN1=		ufraw.1

OPTIONS=	CONTRAST "Enable contrast setting option"	on \
		DST	"Use local time for timestamps"		off \
		EXIV2	"Enable EXIF support via exiv2 library"	on \
		LENSFUN	"Enable LensFun library support"	on \
		FITS	"Enable FITS output support"		off \
		GIMP	"Install GIMP plugin"			off \
		GTK	"Build Gtk+2 GUI"			on \
		GNOME	"Register .desktop file and GConf2 schemas" off

.include <bsd.port.options.mk>

.if defined(WITH_CONTRAST)
CONFIGURE_ARGS+=	--enable-contrast
.endif

.if defined(WITH_DST)
CONFIGURE_ARGS+=	--enable-dst-correction
.endif

.if defined(WITH_EXIV2)
LIB_DEPENDS+=	exiv2.12:${PORTSDIR}/graphics/exiv2
.else
PC_FALSE+=	exiv2
.endif

.if defined(WITH_LENSFUN)
LIB_DEPENDS+=	lensfun.2:${PORTSDIR}/graphics/lensfun
.else
PC_FALSE+=	lensfun
.endif

.if defined(WITH_FITS)
LIB_DEPENDS+=	cfitsio.0:${PORTSDIR}/astro/cfitsio
.else
PC_FALSE+=	cfitsio
.endif

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp-2.0.0:${PORTSDIR}/graphics/gimp-app
PLIST_SUB+=	GIMP=""
.else
CONFIGURE_ARGS+=--without-gimp
PC_FALSE+=	gimp
PLIST_SUB+=	GIMP="@comment "
.endif

.if defined(WITH_GTK)
LIB_DEPENDS+=	gtkimageview.0:${PORTSDIR}/x11-toolkits/gtkimageview
PLIST_FILES+=	bin/ufraw
.else
CONFIGURE_ARGS+=--without-gtk
.endif

.if defined(WITH_GNOME)
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
	@${INSTALL_SCRIPT} ${LOCALBASE}/share/glib-2.0/gettext/mkinstalldirs \
		${WRKSRC}

post-install:
.if defined(WITH_GNOME)
	@${SETENV} GCONF_CONFIG_SOURCE=${GCONF_CONFIG_SOURCE} \
		gconftool-2 --makefile-install-rule \
		${PREFIX}/etc/gconf/schemas/${PORTNAME}.schemas
	@-update-desktop-database
.endif

.include <bsd.port.mk>
