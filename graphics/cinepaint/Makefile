# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	cinepaint
DISTVERSION=	1.0-4
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/CinePaint/CinePaint-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Editing tool used for painting and retouching of movies

LICENSE=	GPLv2 LGPL21 MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libftgl.so:${PORTSDIR}/graphics/ftgl \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
    		libfltk.so:${PORTSDIR}/x11-toolkits/fltk

OPTIONS_DEFINE=	OYRANOS PRINT
OYRANOS_DESC=	ICC profile support via Oyranos
PRINT_DESC=	Gutenprint (gimp-print) plugin

USES=		desktop-file-utils gettext gmake libtool pkgconfig
USE_XORG=	xmu
USE_GNOME=	gtk20
USE_GHOSTSCRIPT_RUN=yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
ACLOCAL_ARGS=	-I aclocal
AUTOMAKE_ARGS=	--copy --force-missing --foreign --add-missing
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VER="${DISTVERSION}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOYRANOS}
LIB_DEPENDS+=	liboyranos.so:${PORTSDIR}/graphics/oyranos
.else
CONFIGURE_ENV+=	ac_cv_path_OY_CONFIG=no
.endif

.if ${PORT_OPTIONS:MPRINT}
LIB_DEPENDS+=	libgutenprint.so:${PORTSDIR}/print/gutenprint-base
PLIST_SUB+=	PRINT=""
.else
CONFIGURE_ARGS+=	--disable-print
PLIST_SUB+=	PRINT="@comment "
.endif

post-extract:
	@${LN} -sf gimprc.in ${WRKSRC}/cinepaintrc.in
	@${LN} -sf gimprc_user.in ${WRKSRC}/cinepaintrc_user.in

post-patch:
	@${REINPLACE_CMD} -e \
		'/^pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata| ; \
		 s|gimprc|cinepaintrc|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e \
		'/cms-profile-path/s|".*"|"${LOCALBASE}/share/color/icc"| ; \
		 s|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/cinepaintrc.in
	@${REINPLACE_CMD} -e \
		's|gimprc|cinepaintrc|g' \
		${WRKSRC}/user_install.in
	@${REINPLACE_CMD} -e \
		's|static GDrawableType|static GImageType|' \
		${WRKSRC}/plug-ins/psd/psd.c

.include <bsd.port.mk>
