PORTNAME=	root
DISTVERSION=	6.36.00
CATEGORIES=	devel science math parallel python
MASTER_SITES=	https://root.cern/download/
DISTFILES=	${PORTNAME}_v${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	erik@tenku.dk
COMMENT=	Data analysis framework made at CERN
WWW=		https://root.cern/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL2_1.txt

BROKEN_i386=	std::uint64_t to std::size_t narrowing conversion issue introduced in version 6.34.02

BUILD_AND_RUN_DEPENDS=	bash:shells/bash \
		nlohmann-json>=3:devel/nlohmann-json
BUILD_DEPENDS=	${BUILD_AND_RUN_DEPENDS}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2 \
		libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${BUILD_AND_RUN_DEPENDS}

USES=		cmake desktop-file-utils iconv shebangfix

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
		etc/pdg_table_update.py \
		etc/runfirefox.sh
# add a port-specific shebang to be replaced
python_OLD_CMD+=	"/usr/bin/env @python@"

# Flags and environment variables for building
CMAKE_ON=	builtin_clang builtin_cling builtin_llvm builtin_openui5 \
		fail-on-missing geom gnuinstall rpath shared soversion
CMAKE_OFF=	arrow builtin_cfitsio builtin_cppzmq builtin_davix builtin_fftw3 \
		builtin_freetype builtin_ftgl builtin_gif builtin_gl2ps builtin_glew \
		builtin_gsl builtin_jpeg builtin_lz4 builtin_lzma builtin_nlohmannjson \
		builtin_openssl builtin_pcre builtin_png builtin_tbb builtin_unuran \
		builtin_vc builtin_vdt builtin_veccore builtin_xrootd builtin_xxhash \
		builtin_zeromq builtin_zlib builtin_zstd cefweb clad cocoa cuda cudnn daos \
		dcache fcgi fftw3 geombuilder gviz html libcxx llvm13_broken_tests macos_native \
		memory_termination minuit2_mpi minuit2_omp mpi odbc proof pythia8 r \
		roofit_multiprocess runtime_cxxmodules shadowpw test_distrdf_pyspark \
		tmva-gpu tmva-rmva tmva-sofie unfold unuran uring use_gsl_cblas vc vecgeom \
		win_broken_tests winrtdebug

# See https://root.cern/install/build_from_source/#all-build-options
OPTIONS_DEFINE=	DOCS ASIMAGE DATAFRAME DAVIX FITS FORTRAN GDML HTTP IMT MATHMORE \
		MYSQL OPENGL PGSQL PYROOT QT6WEB ROOFIT ROOT7 SPECTRUM SQLITE SSL TMLP TMVAML \
		VDT WEBGUI X11 XML XROOTD
OPTIONS_DEFAULT=	ASIMAGE CLAD DATAFRAME DAVIX FITS GDML HTTP IMT MATHMORE OPENGL \
		PYROOT ROOFIT ROOT7 SPECTRUM SSL TMLP TMVAML VDT WEBGUI X11 XML XROOTD
OPTIONS_SUB=	yes

ASIMAGE_CMAKE_BOOL=	asimage asimage_tiff
ASIMAGE_DESC=		Enable support for image processing via libAfterImage
ASIMAGE_IMPLIES=	X11
ASIMAGE_LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff
ASIMAGE_USES=	jpeg

# TODO: clad can only be included in ROOT's configure stage
# with network access, however, a port of clad is available -- patch
#CLAD_CMAKE_BOOL=	clad
#CLAD_DESC=		Build clad, the cling automatic differentiation plugin
#CLAD_LIB_DEPENDS=	libclad.so:math/clad
#CLAD_CMAKE_ON=	-DCLAD_SOURCE_DIR=

DATAFRAME_CMAKE_BOOL=	dataframe
DATAFRAME_DESC=			Enable ROOT RDataFrame

DAVIX_CMAKE_BOOL=	davix
DAVIX_DESC=		Enable support for Davix (HTTP/WebDAV access)
DAVIX_LIB_DEPENDS=	libdavix.so:www/davix
DAVIX_USES=	pkgconfig

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
OPENGL_IMPLIES=	X11 ASIMAGE
OPENGL_LIB_DEPENDS=	libftgl.so:graphics/ftgl \
		libgl2ps.so:print/gl2ps
OPENGL_USES=	gl
OPENGL_USE=		gl=glew,glu,opengl

PGSQL_CMAKE_BOOL=	pgsql
PGSQL_DESC=		Enable support for PostgreSQL
PGSQL_USES=		pgsql:13+

# TODO: 'tpython' is new since 6.34; look into its implications
PYROOT_CMAKE_BOOL=	pyroot tpython tmva-pymva
PYROOT_DESC=		Enable bindings between Python and C++ with PyROOT
PYROOT_BUILD_DEPENDS=	${PYNUMPY}
PYROOT_USES=		python:3.9+,build,run
PYROOT_USES_OFF=	python:3.9+,build

QT6WEB_CMAKE_BOOL=	qt6web
QT6WEB_DESC=		Enable support for Qt6 web-based display
QT6WEB_IMPLIES=	WEBGUI OPENGL
QT6WEB_USES=	qt:6
QT6WEB_USE=	qt=base,declarative,positioning,webchannel,webengine

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
TMLP_IMPLIES=	TMVAML MATHMORE

TMVAML_CMAKE_BOOL=	tmva tmva-cpu
TMVAML_DESC=		Build TMVA multi variate analysis library, including TMVA with CPU support for deep learning
TMVAML_IMPLIES=	IMT MATHMORE
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

ROOT_CLANG_VER=	18

PLIST_SUB+=	PYVER="${PYTHON_VER:S/./_/}" \
		ROOT_CLANG_VER="${ROOT_CLANG_VER}" \
		SHLIB_SHVER="${DISTVERSION:R}" \
		SHLIB_VER="${DISTVERSION}"

# A few headers are only installed on aarch64
.if ${OPSYS} == FreeBSD && ${ARCH} == "aarch64"
PLIST_SUB+=	ONLY_INSTALLED_ON_AARCH64=""
.else
PLIST_SUB+=	ONLY_INSTALLED_ON_AARCH64="@comment "
.endif

# Files in ${PREFIX}lib/root/__pycache__ have links into WRKDIR and should not be staged
# Files in wrkdirs are generated during build of libAfterImage and should not be staged
post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/root/__pycache__
	${RM} -r ${STAGEDIR}/wrkdirs

.include <bsd.port.mk>
