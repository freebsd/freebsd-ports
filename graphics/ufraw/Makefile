# New ports collection makefile for:	UFRaw
# Date created:				Sun 10 Apr 2005 14:44:15 BST
# Whom:					Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ufraw
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read and manipulate raw images from digital cameras

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.6:${PORTSDIR}/graphics/png \
		lcms.1:${PORTSDIR}/graphics/lcms

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --enable-extras
USE_GETTEXT=	yes
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
PC_FALSE=	cinepaint

MAN1=		ufraw.1

OPTIONS=	CONTRAST "Enable contrast setting"		on \
		DST	"Use local time for timestamps"		off \
		EXIV2	"Enable EXIF support via exiv2 library"	on \
		LENSFUN	"Enable LensFun library support"	off \
		FITS	"Enable FITS output support"		off \
		GIMP	"Install GIMP UFRaw plugin"		off \
		GTK	"Build the Gtk+2 GUI"			on

.include <bsd.port.pre.mk>

.if defined(WITH_CONTRAST)
CONFIGURE_ARGS+=	--enable-contrast
.endif

.if defined(WITH_DST)
CONFIGURE_ARGS+=	--enable-dst-correction
.endif

.if defined(WITH_EXIV2)
LIB_DEPENDS+=	exiv2.10:${PORTSDIR}/graphics/exiv2
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
PC_FALSE+=	gimp
PLIST_SUB+=	GIMP="@comment "
.endif

.if defined(WITH_GTK)
LIB_DEPENDS+=	gtkimageview.0:${PORTSDIR}/x11-toolkits/gtkimageview
PLIST_FILES+=	bin/ufraw
.endif

post-patch:
	@${REINPLACE_CMD} -e '18s|^$$|#include <sys/types.h>|' \
		${WRKSRC}/dcraw.h
# Avoid conflict with `graphics/dcraw' and rename the binary
	@${REINPLACE_CMD} -e '/@schemasdir/s|datadir|sysconfdir| ; \
		s|dcraw\$$(EXEEXT)|${PORTNAME}-&|' ${WRKSRC}/Makefile.in
.for i in ${PC_FALSE}
	@${REINPLACE_CMD} -e '/PKG_CONFIG.*${i}/s|$$PKG_CONFIG|${FALSE}|' \
		${WRKSRC}/configure
.endfor

pre-build:
	@${INSTALL_SCRIPT} ${LOCALBASE}/share/glib-2.0/gettext/mkinstalldirs \
		${WRKSRC}

.include <bsd.port.post.mk>
