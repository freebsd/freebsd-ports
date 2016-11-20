# $FreeBSD$

PORTNAME=	oyranos
PORTVERSION=	0.9.5
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Oyranos/Oyranos%20${PORTVERSION:C|(.*)\.[0-9]*$|\1|}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Colour Management System (CMS)

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen
RUN_DEPENDS=	${LOCALBASE}/share/color/icc/OpenICC/sRGB.icc:graphics/icc-profiles-openicc \
		${LOCALBASE}/share/color/icc/basICColor/ISOcoated_v2_300_bas.ICC:graphics/icc-profiles-basiccolor
LIB_DEPENDS=	libraw.so:graphics/libraw \
		libexiv2.so:graphics/exiv2 \
		libpng.so:graphics/png \
		libcairo.so:graphics/cairo \
		libyajl.so:devel/yajl \
		libfltk.so:x11-toolkits/fltk \
		libcups.so:print/cups \
		libxdot.so:graphics/graphviz \
		liblcms.so:graphics/lcms \
		liblcms2.so:graphics/lcms2 \
		libXcm.so:x11/libXcm

BROKEN_FreeBSD_9=	does not build

USES=		cmake gettext iconv pkgconfig tar:bzip2
USE_GL=		yes
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USE_XORG=	xfixes xinerama xrandr xxf86vm
CMAKE_ARGS+=	-DXDG_CONFIG_DIR=${PREFIX}/etc/xdg
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_JOBS_UNSAFE=yes

PORTDOCS=	*

.include <bsd.port.pre.mk>

PLIST_SUB+=	VER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|lib|libdata|' \
		${WRKSRC}/extras/CMakeLists.txt

.if exists(/usr/bin/clang) && ${OSVERSION} > 901502
CC=		/usr/bin/clang
CXX=		/usr/bin/clang++
.else
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
