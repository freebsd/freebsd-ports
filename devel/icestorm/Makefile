# Created by: Johnny Sorocil <jsorocil@gmail.com>
# $FreeBSD$

PORTNAME=	icestorm
PORTVERSION=	g20180310
CATEGORIES=	devel

MAINTAINER=	jsorocil@gmail.com
COMMENT=	IceStorm tools for Lattice iCE40 FPGAs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libftdi1.so:devel/libftdi1

USES=		gmake python:3.3+ shebangfix pkgconfig
SHEBANG_FILES=	${WRKSRC}/icebox/*.py \
		${WRKSRC}/icebox/Makefile

USE_GITHUB=	yes
GH_ACCOUNT=	cliffordwolf
GH_TAGNAME=	4476d83f76fa0222be0b691fe27c1e0228266f82

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icepack
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icepll
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icebram
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/iceprog
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icemulti
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/icetime

.include <bsd.port.mk>
