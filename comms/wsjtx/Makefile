PORTNAME=	wsjtx
DISTVERSION=	3.0.1
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt/${PORTNAME}-${PORTVERSION}
DISTNAME=	wsjtx-${PORTVERSION}-src

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
		libhamlib.so:comms/hamlib \
		libxslt.so:textproc/libxslt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		cmake:noninja compiler:c++11-lang fortran gl libedit \
		makeinfo pkgconfig qt:5 readline
USE_GL=		glu
USE_QT=		core gui network widgets \
		multimedia concurrent printsupport serialport sql sql-sqlite3 \
		buildtools:build linguisttools:build qmake:build testlib websockets

CONFLICTS_INSTALL=	wsjtz

# for detailed debugging uncomment the next line
CMAKE_ARGS+=   --debug-output --trace
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for More actual than formal arguments in procedure call at (1)
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
