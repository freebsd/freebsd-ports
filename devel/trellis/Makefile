PORTNAME=	trellis
PORTVERSION=	g2026103100
CATEGORIES=	devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Documenting the Lattice ECP5 bit-stream format
WWW=		https://github.com/YosysHQ/prjtrellis

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs

USES=		compiler:c++14-lang cmake python shebangfix

SHEBANG_FILES=	${WRKSRC}/timing/util/cell_html.py \
		${WRKSRC}/timing/util/cell_timings.py

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_PROJECT=	prjtrellis
GH_TAGNAME=	2d12005ab9703ff60603d7ae91dca254939e671f
GH_TUPLE=	YosysHQ:prjtrellis-db:9754ff473bfaa1e6edfaf57ce13bd447c76a88f6:database/database

CMAKE_SOURCE_PATH=	${WRKSRC}/libtrellis
CMAKE_ARGS=		-DCURRENT_GIT_VERSION=${GH_TAGNAME}

.include <bsd.port.mk>
