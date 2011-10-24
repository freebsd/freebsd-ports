# New ports collection makefile for:	UFRaw
# Date created:				Sun 10 Apr 2005 14:44:15 BST
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ufraw
PORTVERSION=	0.18
PORTREVISION=	0
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read and manipulate raw images from digital cameras

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.6:${PORTSDIR}/graphics/png \
		gtkimageview.0:${PORTSDIR}/x11-toolkits/gtkimageview \
		lcms.1:${PORTSDIR}/graphics/lcms

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 glib20 gnomehack intltool intlhack libartlgpl2 pkgconfig

LDFLAGS+=	-L"${LOCALBASE}/lib" ${PTHREAD_LIBS}
CPPFLAGS+=	-I"${LOCALBASE}/include"
PC_FALSE+=	cinepaint

OPTIONS=	CONTRAST "Enable contrast setting"		on	\
		DST	"Use local time for timestamps"	off	\
		EXIV2	"EXIF support via exiv2 library"	on	\
		FITS	"Enable FITS output support"		off	\
		GIMP	"Install GIMP UFRaw plugin"		on	\
		LENSFUN	"Build with LensFun library support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EXIV2)
LIB_DEPENDS+=	exiv2.10:${PORTSDIR}/graphics/exiv2
.else
PC_FALSE+=	exiv2
.endif
.if !defined(WITHOUT_GIMP)
LIB_DEPENDS+=	gimp-2.0.0:${PORTSDIR}/graphics/gimp-app
PLIST_SUB+=	GIMP=""
.else
PC_FALSE+=	gimp
PLIST_SUB+=	GIMP="@comment "
.endif
.if !defined(WITHOUT_LENSFUN) || exists(${LOCALBASE}/lib/lensfun.so.2)
LIB_DEPENDS+=	lensfun.2:${PORTSDIR}/graphics/lensfun
.endif
.if defined(WITH_FITS) || exists(${LOCALBASE}/lib/libcfitsio.so)
LIB_DEPENDS+=	cfitsio.0:${PORTSDIR}/astro/cfitsio
.endif
.if !defined(WITHOUT_CONTRAST)
CONFIGURE_ARGS+=	--enable-contrast
.endif
.if defined(WITH_DST)
CONFIGURE_ARGS+=	--enable-dst-correction
.endif

MAN1=	ufraw.1

post-patch:
	@${REINPLACE_CMD} -e '18s|^$$|#include <sys/types.h>|' ${WRKSRC}/dcraw.h
	@${REINPLACE_CMD} -e '/@schemasdir/s|datadir|sysconfdir|' \
	    ${WRKSRC}/Makefile.in
.for i in ${PC_FALSE}
	@${REINPLACE_CMD} -e '/PKG_CONFIG.*$i/s|$$PKG_CONFIG|${FALSE}|' \
	    ${WRKSRC}/configure
.endfor

pre-build:
	${INSTALL_SCRIPT} ${LOCALBASE}/share/glib-2.0/gettext/mkinstalldirs \
	    ${WRKSRC}/

.include <bsd.port.post.mk>
