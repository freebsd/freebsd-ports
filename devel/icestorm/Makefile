# Created by: Johnny Sorocil <jsorocil@gmail.com>
# $FreeBSD$

PORTNAME=	icestorm
PORTVERSION=	g20190526
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IceStorm tools for Lattice iCE40 FPGAs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs

USES=		compiler:c++11-lang gmake pkgconfig python:3.3+ shebangfix

SHEBANG_FILES=	${WRKSRC}/icebox/*.py \
		${WRKSRC}/icebox/Makefile

USE_GITHUB=	yes
GH_ACCOUNT=	cliffordwolf
GH_TAGNAME=	710470f9

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icepack
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icepll
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icebram
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/iceprog
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icemulti
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icetime

.include <bsd.port.mk>
