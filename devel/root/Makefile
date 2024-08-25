PORTNAME=	root
DISTVERSION=	6.32.04
CATEGORIES=	devel science math parallel python
MASTER_SITES=	https://root.cern/download/
DISTFILES=	${PORTNAME}_v${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	erik@tenku.dk
COMMENT=	Data analysis framework made at CERN
WWW=		https://root.cern/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL2_1.txt

BUILD_AND_RUN_DEPENDS=	bash:shells/bash \
		nlohmann-json>=3:devel/nlohmann-json
BUILD_DEPENDS=	${BUILD_AND_RUN_DEPENDS}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2 \
		libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${BUILD_AND_RUN_DEPENDS}

USES=		cmake compiler:c++17-lang desktop-file-utils \
		iconv shebangfix

SHEBANG_FILES=	main/python/rootbrowse.py \
		main/python/rootcp.py \
		main/python/rootdrawtree.py \
		main/python/rooteventselector.py \
		main/python/rootls.py \
		main/python/rootmkdir.py \
		main/python/rootmv.py \
		main/python/rootprint.py \
		main/python/rootrm.py \
		main/python/rootslimtree.py \
		config/rootssh \
		etc/dictpch/makepch.py \
		etc/proof/utils/circle.sh \
		etc/proof/utils/crypt \
		etc/proof/utils/pps \
		etc/proof/utils/proofctl.sh \
		etc/proof/utils/proofinstall.sh \
		etc/pdg_table_update.py
# add a port-specific shebang to be replaced
python_OLD_CMD+=	"/usr/bin/env @python@"

# Flags and environment variables for building
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_ON=	builtin_clang builtin_cling builtin_llvm builtin_openui5 gnuinstall \
		rpath runtime_cxxmodules shared soversion
CMAKE_OFF=	arrow builtin_afterimage builtin_cfitsio builtin_cppzmq builtin_davix \
		builtin_fftw3 builtin_freetype builtin_ftgl builtin_gl2ps builtin_glew \
		builtin_gsl builtin_gtest builtin_lz4 builtin_lzma builtin_nlohmannjson \
		builtin_openssl builtin_pcre builtin_tbb builtin_unuran builtin_vc builtin_vdt \
		builtin_veccore builtin_xrootd builtin_xxhash builtin_zeromq builtin_zlib \
		builtin_zstd cefweb clad cocoa cuda cudnn daos davix dcache fcgi fftw3 gviz \
		libcxx llvm13_broken_tests macos_native memory_termination minuit2_mpi \
		minuit2_omp mpi odbc proof pythia8 qt5web qt6web r roofit_multiprocess \
		shadowpw test_distrdf_dask test_distrdf_pyspark tmva-gpu tmva-rmva tmva-sofie \
		unfold unuran uring vc veccore vecgeom win_broken_tests winrtdebug
CONFIGURE_WRKSRC?=	${WRKDIR}/.build
MAKE_ENV+=		ROOTSYS=${CONFIGURE_WRKSRC}

# Port build options; DOCS also on by default
# See https://root.cern/install/build_from_source/#all-build-options
OPTIONS_DEFINE=	DOCS ASIMAGE DATAFRAME FITS FORTRAN GDML HTTP IMT MATHMORE MYSQL \
		OPENGL PGSQL PYROOT ROOFIT ROOT7 SPECTRUM SQLITE SSL TMLP TMVAML VDT WEBGUI \
		X11 XML XROOTD
OPTIONS_DEFAULT=	ASIMAGE DATAFRAME FITS GDML HTTP IMT MATHMORE OPENGL PYROOT \
		ROOFIT ROOT7 SPECTRUM SSL TMLP TMVAML VDT WEBGUI X11 XML XROOTD
OPTIONS_SUB=	yes

ASIMAGE_CMAKE_BOOL=	asimage
ASIMAGE_DESC=		Enable support for image processing via libAfterImage
ASIMAGE_IMPLIES=	X11
ASIMAGE_LIB_DEPENDS=	libAfterImage.so:graphics/libafterimage \
		libgif.so:graphics/giflib \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff
ASIMAGE_USES=	gettext-runtime gnome jpeg
ASIMAGE_USE=	gnome=cairo,gdkpixbuf2,glib20,librsvg2

# TODO: clad can only be included in ROOT's configure stage
# with network access, however, a port of clad is available -- patch
#CLAD_CMAKE_BOOL=	clad
#CLAD_DESC=		Build clad, the cling automatic differentiation plugin (requires network)
#CLAD_LIB_DEPENDS=	libclad.so:math/clad

DATAFRAME_CMAKE_BOOL=	dataframe
DATAFRAME_DESC=			Enable ROOT RDataFrame

# TODO: davix only comes with pkgconfig file on fbsd, while
# ROOT's configure stage relies on find_package() -- patch
#DAVIX_CMAKE_BOOL=	davix
#DAVIX_DESC=		Enable support for Davix (HTTP/WebDAV access)
#DAVIX_IMPLIES=	libuuid xml2 openssl
#DAVIX_LIB_DEPENDS=	libdavix.so:www/davix

FITS_CMAKE_BOOL=	fitsio
FITS_DESC=		Enable support for reading FITS images
FITS_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl

FORTRAN_CMAKE_BOOL=	fortran
FORTRAN_DESC=		Build Fortran components of ROOT
FORTRAN_USES=		fortran

GDML_CMAKE_BOOL=	gdml
GDML_DESC=		Enable support for GDML (Geometry Description Markup Language)

HTTP_CMAKE_BOOL=	http
HTTP_DESC=		Enable support for HTTP server
HTTP_IMPLIES=	ROOT7 WEBGUI

IMT_CMAKE_BOOL=	imt
IMT_DESC=		Enable support for implicit multi-threading via Intel® Thread Building Blocks (TBB)
IMT_LIB_DEPENDS=	libtbb.so:devel/onetbb

MATHMORE_CMAKE_BOOL=	mathmore
MATHMORE_DESC=		Build libMathMore extended math library
MATHMORE_LIB_DEPENDS=	libgsl.so:math/gsl

MYSQL_CMAKE_BOOL=	mysql
MYSQL_DESC=		Enable support for MySQL databases
MYSQL_LIB_DEPENDS=	libunwind.so:devel/libunwind
MYSQL_USES=		mysql ssl

OPENGL_CMAKE_BOOL=	opengl
OPENGL_DESC=		Enable support for OpenGL
OPENGL_IMPLIES=	X11
OPENGL_LIB_DEPENDS=	libftgl.so:graphics/ftgl \
		libgl2ps.so:print/gl2ps
OPENGL_USES=	gl
OPENGL_USE=		gl=glew,glu,opengl

PGSQL_CMAKE_BOOL=	pgsql
PGSQL_DESC=		Enable support for PostgreSQL
PGSQL_USES=		pgsql:13+

PYROOT_CMAKE_BOOL=	pyroot tmva-pymva
PYROOT_DESC=		Enable bindings between Python and C++ with PyROOT
PYROOT_BUILD_DEPENDS=	${PYNUMPY}
PYROOT_USES=		python:3.9+,build,run
PYROOT_USES_OFF=	python:3.9+,build

ROOFIT_CMAKE_BOOL=	roofit
ROOFIT_DESC=		Build the advanced fitting package RooFit, and RooStats for statistical tests

ROOT7_CMAKE_BOOL=	root7
ROOT7_DESC=		Build ROOT 7 components of ROOT

SPECTRUM_CMAKE_BOOL=	spectrum
SPECTRUM_DESC=		Enable support for TSpectrum

SQLITE_CMAKE_BOOL=	sqlite
SQLITE_DESC=		Enable support for SQLite
SQLITE_USES=		sqlite

SSL_CMAKE_BOOL=	ssl
SSL_DESC=		Enable support for SSL encryption via OpenSSL
SSL_USES=		ssl

TMLP_CMAKE_BOOL=	mlp
TMLP_DESC=		Enable support for TMultilayerPerceptron classes' federation
TMLP_IMPLIES=	TMVAML

TMVAML_CMAKE_BOOL=	tmva tmva-cpu
TMVAML_DESC=		Build TMVA multi variate analysis library, including TMVA with CPU support for deep learning
TMVAML_IMPLIES=	IMT
TMVAML_LIB_DEPENDS=	libopenblas.so:math/openblas

VDT_CMAKE_BOOL=	vdt
VDT_DESC=		Enable support for VDT (fast and vectorisable mathematical functions)
VDT_LIB_DEPENDS=	libvdt.so:math/vdt

WEBGUI_CMAKE_BOOL=	webgui
WEBGUI_DESC=		Build Web-based UI components of ROOT
WEBGUI_IMPLIES=	HTTP ROOT7

X11_CMAKE_BOOL=	x11
X11_DESC=		Enable support for X11/Xft
X11_USES=		xorg
X11_USE=		xorg=ice,sm,x11,xau,xaw,xcb,xcomposite,xcursor,xdamage,xdmcp,xext \
		xorg=xfixes,xfont,xfont2,xft,xi,xinerama,xkbfile,xmu,xpm,xrandr,xrender \
		xorg=xres,xscrnsaver,xt,xv,xxf86vm

XML_CMAKE_BOOL=		xml
XML_DESC=		Enable support for XML
XML_USES=		gnome
XML_USE=		gnome=libxml2

XROOTD_CMAKE_BOOL=	xrootd
XROOTD_DESC=		Enable support for XRootD file server and client
XROOTD_LIB_DEPENDS=	libXrdCl.so:databases/xrootd

.include <bsd.port.options.mk>

ROOT_CLANG_VER=	16

PLIST_SUB+=	PYVER="${PYTHON_VER:S/./_/}" \
		ROOT_CLANG_VER="${ROOT_CLANG_VER}" \
		SHLIB_SHVER="${DISTVERSION:R}" \
		SHLIB_VER="${DISTVERSION}"

# Some .modulemap, .pcm and .idx files are not installed on aarch64, a few headers are only installed on aarch64
.if ${OPSYS} == FreeBSD && ${ARCH} == "aarch64"
PLIST_SUB+=	NOT_INSTALLED_ON_AARCH64="@comment " ONLY_INSTALLED_ON_AARCH64=""
.else
PLIST_SUB+=	NOT_INSTALLED_ON_AARCH64="" ONLY_INSTALLED_ON_AARCH64="@comment "
.endif

# atexit-like commands need 'throw()' specifier on 15aarch64
.if ${OPSYS} == FreeBSD && ${ARCH} == "aarch64" && ${OSVERSION} > 1499999
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-interpreter_cling_lib_Interpreter_Interpreter.cpp.15aarch64
.endif

# std_config.pcm exclusive to FreeBSD 14.0
.if ${OPSYS} == FreeBSD && ${OSREL} == 14.0
PLIST_SUB+=	ONLY_INSTALLED_ON_FBSD140=""
.else
PLIST_SUB+=	ONLY_INSTALLED_ON_FBSD140="@comment "
.endif

# Port patch removes implicit use of system's module.modulemap and applies
# explicit use of the same module.modulemap, with modifications, provided
# by the port
eq_OSREL=	${OSREL}
.if ${OPSYS} == FreeBSD && ${OSREL} == 14.1
# module.modulemap identical on 14.1 and 15.0
eq_OSREL=	15.0
.endif
post-patch:
	${CP} \
  ${PATCHDIR}/interpreter-cling-include-cling-std__fbsd${eq_OSREL}.modulemap \
  ${WRKSRC}/interpreter/cling/include/cling/std_fbsd.modulemap

# Files in lib/root/__pycache__ have links into WRKDIR and should not be staged. This happens even when PYROOT option is OFF.
post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/root/__pycache__

.include <bsd.port.mk>
