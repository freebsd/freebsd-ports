PORTNAME=	criterion
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.2
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C and C++ unit testing framework for the 21st century
WWW=		https://github.com/Snaipe/Criterion

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/klib/khash.h:devel/klib \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		nanopb>0:devel/nanopb \
		cmake:devel/cmake-core \
		protoc:devel/protobuf
LIB_DEPENDS=	libboxfort.so:devel/boxfort \
		libffi.so:devel/libffi \
		libgit2.so:devel/libgit2 \
		libnanomsg.so:net/nanomsg
RUN_DEPENDS=	nanopb>0:devel/nanopb

USES=		gettext localbase:ldflags meson python pkgconfig shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Snaipe
GH_PROJECT=	Criterion
GH_TUPLE=	MrAnno:debugbreak:83bf7e9:debugbreak

SHEBANG_FILES=	src/protocol/gen-pb.py

CFLAGS+=	-fPIC \
		-I${LOCALBASE}/include/klib \
		-I${WRKSRC_debugbreak}

MESON_ARGS=	-Dtests=false -Dsamples=false

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

quick-test:
	@cd ${TEST_WRKSRC} && \
		${CC} ${CFLAGS} ${LDFLAGS} -I${STAGEDIR}${PREFIX}/include \
			${STAGEDIR}${PREFIX}/lib/libcriterion.a \
			-L${LOCALBASE}/lib -lboxfort -lprotobuf-nanopb -lgit2 -lnanomsg -lintl \
			${FILESDIR}/example.c && \
		./a.out # test succeeds when simple::Test fails with assertion

do-test:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} --reconfigure ${CONFIGURE_ARGS} -Dtests=true && \
	cd ${BUILD_WRKSRC} && \
		${DO_MAKE_BUILD} ${ALL_TARGET} test

.include <bsd.port.mk>
