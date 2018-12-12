# $FreeBSD$

PORTNAME=	oyranos
PORTVERSION=	0.9.6
PORTREVISION=	7
CATEGORIES=	graphics

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Colour Management System (CMS)

LICENSE=	BSD3CLAUSE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	${LOCALBASE}/share/color/icc/OpenICC/sRGB.icc:graphics/icc-profiles-openicc \
		${LOCALBASE}/share/color/icc/basICColor/ISOcoated_v2_300_bas.ICC:graphics/icc-profiles-basiccolor \
		xcalib:x11/xcalib
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
		libXcm.so:x11/libXcm \
		libltdl.so:devel/libltdl \
		libfontconfig.so:x11-fonts/fontconfig \
		libOpenICC.so:graphics/openicc-config

USE_GITHUB=	yes
GH_ACCOUNT=	oyranos-cms
USES=		cmake compiler:c++11-lib desktop-file-utils gettext iconv jpeg pkgconfig qt:4
USE_GL=		gl
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_QT=		corelib gui moc_build qmake_build rcc_build uic_build
USE_XORG=	ice sm x11 xcursor xext xfixes xinerama xrandr xft xxf86vm
CMAKE_ARGS+=	-DXDG_CONFIG_DIR=${PREFIX}/etc/xdg
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOXYGEN DOCS
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:devel/doxygen

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	VER=${PORTVERSION}

.if !exists(/usr/bin/clang)
USE_GCC=   yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib|libdata|' \
		${WRKSRC}/extras/CMakeLists.txt

.include <bsd.port.mk>
