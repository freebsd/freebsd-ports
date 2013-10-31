# $FreeBSD$

PORTNAME=	oyranos
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Oyranos/Oyranos%20${PORTVERSION:C|(.*)\.[0-9]*$|\1|}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Colour Management System (CMS)

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
RUN_DEPENDS=	${LOCALBASE}/share/color/icc/OpenICC/sRGB.icc:${PORTSDIR}/graphics/icc-profiles-openicc \
		${LOCALBASE}/share/color/icc/basICColor/ISOcoated_v2_300_bas.ICC:${PORTSDIR}/graphics/icc-profiles-basiccolor
LIB_DEPENDS=	libraw.so:${PORTSDIR}/graphics/libraw \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libyajl.so:${PORTSDIR}/devel/yajl \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libcups.so:${PORTSDIR}/print/cups-client \
		libxdot.so:${PORTSDIR}/graphics/graphviz \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libXcm.so:${PORTSDIR}/x11/libXcm

USES=		cmake gettext iconv pkgconfig
USE_BZIP2=	yes
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
