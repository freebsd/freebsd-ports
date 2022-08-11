PORTNAME=	criterion
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C and C++ unit testing framework for the 21st century

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR} \
		nanopb>0:devel/nanopb \
		cmake:devel/cmake \
		protoc:devel/protobuf
LIB_DEPENDS=	libboxfort.so:devel/boxfort \
		libffi.so:devel/libffi \
		libgit2.so:devel/libgit2 \
		libnanomsg.so:net/nanomsg \
		libprotobuf-nanopb.so:devel/nanopb
RUN_DEPENDS=	nanopb>0:devel/nanopb

USES=		gettext localbase:ldflags meson python pkgconfig shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Snaipe
GH_PROJECT=	Criterion
GH_TUPLE=	attractivechaos:klib:cdb7e92:klib/dependencies/klib \
		MrAnno:debugbreak:83bf7e9:debugbreak/dependencies/debugbreak

SHEBANG_FILES=	src/protocol/gen-pb.py

MESON_ARGS=	-Dtests=false -Dsamples=false

quick-test:
	@cd ${TEST_WRKSRC} && \
		${CC} ${CFLAGS} ${LDFLAGS} -I${STAGEDIR}${PREFIX}/include \
			${STAGEDIR}${PREFIX}/lib/libcriterion.a \
			-L${LOCALBASE}/lib -lboxfort -lprotobuf-nanopb -lgit2 -lnanomsg -lintl \
			${FILESDIR}/example.c && \
		./a.out # test succeeds when simple::Test fails with assertion

do-test:
	@cd ${WRKSRC} && \
		${RM} -rf _build && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} -Dtests=true -Dsamples=false && \
	cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} test

.include <bsd.port.mk>
