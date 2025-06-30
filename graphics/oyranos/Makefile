PORTNAME=	oyranos
PORTVERSION=	0.9.6
PORTREVISION=	18
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Colour Management System (CMS)
WWW=		http://www.oyranos.org/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/share/color/icc/OpenICC/sRGB.icc:graphics/icc-profiles-openicc \
		${LOCALBASE}/share/color/icc/basICColor/ISOcoated_v2_300_bas.ICC:graphics/icc-profiles-basiccolor \
		xcalib:x11/xcalib
LIB_DEPENDS=	libraw.so:graphics/libraw \
		libexiv2.so:graphics/exiv2 \
		libpng.so:graphics/png \
		libcairo.so:graphics/cairo \
		libyajl.so:devel/yajl \
		libcups.so:print/cups \
		libxdot.so:graphics/graphviz \
		liblcms.so:graphics/lcms \
		liblcms2.so:graphics/lcms2 \
		libXcm.so:x11/libXcm \
		libltdl.so:devel/libltdl \
		libfontconfig.so:x11-fonts/fontconfig \
		libOpenICC.so:graphics/openicc-config

USE_GITHUB=	yes
GH_ACCOUNT=	oyranos-cms
USES=		cmake compiler:c++11-lib desktop-file-utils gettext gl gnome \
		iconv jpeg pkgconfig qt:5 xorg
USE_GL=		gl
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_QT=		core gui widgets x11extras \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xcursor xext xfixes xinerama xrandr xrender xft xxf86vm
CMAKE_ARGS+=	-DXDG_CONFIG_DIR=${PREFIX}/etc/xdg
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS DOXYGEN FLTK
OPTIONS_SUB=	yes
FLTK_DESC=	Build FLTK-based auxiliary programs
FLTK_BROKEN=	fails to build, see https://github.com/oyranos-cms/oyranos/issues/62

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen

FLTK_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	VER=${PORTVERSION}

.if !exists(/usr/bin/clang)
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib|libdata|' \
		${WRKSRC}/extras/CMakeLists.txt

.include <bsd.port.mk>
