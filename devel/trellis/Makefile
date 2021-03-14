# $FreeBSD$

PORTNAME=	trellis
PORTVERSION=	g20190422
PORTREVISION=	3
CATEGORIES=	devel

# Add Python 3.8 to search list in ${WRKSRC}/libtrellis/CMakeLists.txt
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	2784291454a0307cf131acb5f0f68acc1eb4ffc3.patch:-p1

MAINTAINER=	manu@FreeBSD.Org
COMMENT=	Documenting the Lattice ECP5 bit-stream format

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libboost_atomic.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		${PY_BOOST} \
		libboost_thread.so:devel/boost-libs

USES=		compiler:c++14-lang cmake python:3.5+ shebangfix

SHEBANG_FILES=	${WRKSRC}/timing/util/cell_html.py \
		${WRKSRC}/timing/util/cell_timings.py

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SymbiFlow
GH_PROJECT=	prjtrellis
GH_TAGNAME=	5eb0ad87
GH_TUPLE=	SymbiFlow:prjtrellis-db:d0b219af:database/database

CMAKE_SOURCE_PATH=	${WRKSRC}/libtrellis

.include <bsd.port.mk>
