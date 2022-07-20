PORTNAME=	dust3d
DISTVERSION=	1.0.0-rc.6
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	f8339d25ddb79f893413.diff:-p1 821285de824baf01ae99.diff:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open-source 3D modeling software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/config.hpp:devel/boost-libs \
		${LOCALBASE}/include/CGAL/Polygon_mesh_processing/corefinement.h:math/cgal \
		cmake:devel/cmake
LIB_DEPENDS=	libgmp.so:math/gmp libmpfr.so:math/mpfr

USES=		compiler:c++14-lang gmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	huxingyi
USE_QT=		buildtools_build linguisttools_build qmake_build \
		core gui network opengl widgets
ALL_TARGET=	all

DESKTOP_ENTRIES="Dust3D" "${COMMENT}" "${PORTNAME}" "${PORTNAME}" \
		"Application;" false

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == riscv64
EXTRA_PATCHES=	${FILESDIR}/extra-patch-thirdparty_instant-meshes_instant-meshes-dust3d_ext_tbb_src_tbb_tools__api_ittnotify__config.h
.endif

post-patch:
	@${REINPLACE_CMD} -e '/PLATFORM =/s,Linux,${OPSYS},' \
		${WRKSRC}/${PORTNAME}.pro
do-configure:
	cd ${CONFIGURE_WRKSRC} && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

pre-build:
	cd ${BUILD_WRKSRC}/thirdparty/instant-meshes && cmake -B build
	${MAKE_CMD} -C ${BUILD_WRKSRC}/thirdparty/instant-meshes/build

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
