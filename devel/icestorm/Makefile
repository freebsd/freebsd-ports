PORTNAME=		icestorm
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1
CATEGORIES=		devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	IceStorm tools for Lattice iCE40 FPGAs
WWW=		https://www.clifford.at/icestorm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs
BUILD_DEPENDS=	gsed:textproc/gsed

USES=		compiler:c++11-lang gmake pkgconfig python shebangfix

SHEBANG_FILES=	${WRKSRC}/icebox/*.py \
		${WRKSRC}/icebox/Makefile

USE_GITHUB=	yes
GH_ACCOUNT=	yosyshq

BINARY_ALIAS=	python3=${PYTHON_CMD} sed=gsed

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icepack
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icepll
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icebram
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/iceprog
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icemulti
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icetime

.include <bsd.port.mk>
