PORTNAME=	trellis
PORTVERSION=	g2025011100
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Documenting the Lattice ECP5 bit-stream format
WWW=		https://github.com/YosysHQ/prjtrellis

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

USES=		compiler:c++14-lang cmake python shebangfix

SHEBANG_FILES=	${WRKSRC}/timing/util/cell_html.py \
		${WRKSRC}/timing/util/cell_timings.py

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_PROJECT=	prjtrellis
GH_TAGNAME=	14ac883fa639b11fdc98f3cdef87a5d01f79e73d
GH_TUPLE=	YosysHQ:prjtrellis-db:4dda149b9e4f1753ebc8b011ece2fe794be1281a:database/database

CMAKE_SOURCE_PATH=	${WRKSRC}/libtrellis
CMAKE_ARGS=	-DCURRENT_GIT_VERSION=${GH_TAGNAME}

.include <bsd.port.mk>
