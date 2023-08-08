PORTNAME=	trellis
PORTVERSION=	g2022100712
CATEGORIES=	devel

MAINTAINER=	manu@FreeBSD.Org
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
GH_TAGNAME=	35f5affe10
GH_TUPLE=	YosysHQ:prjtrellis-db:35d900a94ff:database/database

CMAKE_SOURCE_PATH=	${WRKSRC}/libtrellis

.include <bsd.port.mk>
