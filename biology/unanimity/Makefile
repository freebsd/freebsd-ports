# $FreeBSD$

PORTNAME=		unanimity
DISTVERSIONPREFIX=	v
DISTVERSION=		3.4.1
PORTREVISION=		4
CATEGORIES=		biology

# As of March 2018, unanimity is no longer open source.
# See https://github.com/PacificBiosciences/ccs.
MAINTAINER=     ports@FreeBSD.org
COMMENT=	Pacific Biosciences consensus library and applications

BROKEN=		unfetchable
DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?

# Very sensitive to pbbam and pbcopper versions!
# Fully test new combinations and upgrade them together.
BUILD_DEPENDS=	seqan>=2.4.0:biology/seqan \
		swig30>=3.0:devel/swig30 \
		${PYNUMPY}
LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs \
		libpbbam.so.0.18.0:biology/pbbam \
		libpbcopper.so.0.4.1:biology/pbcopper
RUN_DEPENDS=	${PYNUMPY}

# Meson needs BOOST_ROOT=${LOCALBASE}
# https://github.com/mesonbuild/meson/issues/2239
USES=		compiler:c++14-lang localbase meson pkgconfig python:2.7
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

CFLAGS_i386=	-msse2 -Wno-c++11-narrowing
LDFLAGS+=	-lexecinfo

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libunanimity.so.3.0.0 \
		${STAGEDIR}${PREFIX}/lib/libunanimity.so.3.0
	${RLN} ${STAGEDIR}${PREFIX}/lib/libunanimity.so.3.0.0 \
		${STAGEDIR}${PREFIX}/lib/libunanimity.so.3

.include <bsd.port.mk>
