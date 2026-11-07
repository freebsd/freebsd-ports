PORTNAME=	wsjtx
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt/${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package
WWW=		https://physics.princeton.edu/pulsar/k1jt/wsjtx.html

LICENSE=	GPLv3

BUILD_DEPENDS=	a2x:textproc/asciidoc \
		asciidoctor:textproc/rubygem-asciidoctor \
		git:devel/git \
		${LOCALBASE}/share/xsl/docbook:textproc/docbook-xsl
LIB_DEPENDS=	libboost_log_setup.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libportaudio.so:audio/portaudio \
		libxslt.so:textproc/libxslt

USES=		cmake:noninja compiler:c++11-lang fortran gl libedit \
		makeinfo pkgconfig qt:5 readline tar:tgz
USE_GITHUB=	yes
USE_GL=		glu
USE_QT=		buildtools:build concurrent core gui linguisttools:build \
		multimedia network printsupport qmake:build serialport sql \
		sql-sqlite3 testlib websockets widgets

# for detailed debugging uncomment the next line
#CMAKE_ARGS+=   --debug-output --trace

CMAKE_ARGS+=	-DUsb_LIBRARY=/usr/lib/libusb.so \
		-DOpenMP_Fortran_FLAGS=-fopenmp \
		-DOpenMP_Fortran_LIB_NAMES=gomp \
		-DHAVE_MATH=FALSE \
		-DLIBM_LIBRARIES=m \
		-DCAMKE_INSTALL_DATAROOTDIR="${DOCSDIR_REL}"
FFLAGS+=	-fallow-argument-mismatch -fopenmp
FCFLAGS=	-fopenmp
CONFLICTS_INSTALL=	wsjtz
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
