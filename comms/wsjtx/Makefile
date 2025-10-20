PORTNAME=	wsjtx
DISTVERSION=	2.5.4
PORTREVISION=	15
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt/${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package
WWW=		https://physics.princeton.edu/pulsar/k1jt/wsjtx.html

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		a2x:textproc/asciidoc \
		git:devel/git \
		${LOCALBASE}/share/xsl/docbook:textproc/docbook-xsl
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libboost_log_setup.so:devel/boost-libs \
		libxslt.so:textproc/libxslt

USES=	cmake:noninja compiler:c++11-lang fortran gl libedit \
		makeinfo pkgconfig qt:5 readline tar:tgz
USE_GL=		glu
USE_QT=		core gui network widgets \
		multimedia concurrent printsupport serialport sql sql-sqlite3 \
		buildtools:build linguisttools:build qmake:build testlib

CONFLICTS_INSTALL=	wsjtz

# for detailed debugging uncomment the next line
#CMAKE_ARGS+=   --debug-output --trace
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

_PATCHES=	wsjtx.patch hamlib.patch

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for More actual than formal arguments in procedure call at (1)
FFLAGS+=	-fallow-argument-mismatch
.endif

_HAMLIB_PATCHES=	configure hamlib.pc.in tests/rigtestlibusb.c src/misc.c
make-hamlib-patch:
	${MV} ${FILESDIR}/hamlib.patch ${FILESDIR}/hamlib.patch.old
. for f in ${_HAMLIB_PATCHES}
	(cd ${WRKDIR}/.build/hamlib-prefix/src;diff -u hamlib/$f.orig hamlib/$f >> ${FILESDIR}/hamlib.patch || true)
. endfor

_WSJTX_PATCHES=	wsjtx_config.h.in CMakeLists.txt Radio.cpp \
		widgets/FrequencyLineEdit.cpp \
		widgets/FrequencyDeltaLineEdit.cpp \
		CMake/Modules/FindUsb.cmake \
		CMake/Modules/FindHamlib.cmake
make-wsjtx-patch:
	${MV} ${FILESDIR}/wsjtx.patch ${FILESDIR}/wsjtx.patch.old
. for f in ${_WSJTX_PATCHES}
	(cd ${WRKDIR}/.build/wsjtx-prefix/src;diff -u wsjtx/$f.orig wsjtx/$f >> ${FILESDIR}/wsjtx.patch || true)
. endfor

post-patch:
.  for _patch in ${_PATCHES}
	# Keep a copy of the blank patch for the post-build target below
	${MV} ${WRKSRC}/${_patch} ${WRKSRC}/${_patch}.orig
	# Copy the patch provided by the ports system
	${CP} ${FILESDIR}/${_patch}  ${WRKSRC}
.  endfor

post-build:
	# With cmake 3.18, the patching stage in the internal build
	# is run again, trick it by removing the patch again.
.  for _patch in ${_PATCHES}
	${MV} ${WRKSRC}/${_patch}.orig  ${WRKSRC}/${_patch}
.  endfor

do-install:
	(cd ${CONFIGURE_WRKSRC};${MAKE} -f Makefile DESTDIR=${STAGEDIR} install)

post-install:
.for f in fcal fmeasure fmtave fst4sim ft8code jt4code jt65code jt9 jt9code \
	message_aggregator msk144code rigctld-wsjtx rigctlcom-wsjtx \
	rigctl-wsjtx udp_daemon q65code q65sim \
	wsjtx wsjtx_app_version wsprd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.post.mk>
