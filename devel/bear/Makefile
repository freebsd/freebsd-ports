# Created by: Jov <amutu@amutu.com>

PORTNAME=	bear
DISTVERSION=	3.0.17
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tool that generates a compilation database for clang tooling

LICENSE=	GPLv3+

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libabsl_hash.so:devel/abseil \
		libcares.so:dns/c-ares \
		libfmt.so:devel/libfmt \
		libgrpc.so:devel/grpc \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rizsotto
GH_PROJECT=	Bear
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR} \
		-DENABLE_FUNC_TESTS=OFF \
		-DENABLE_UNIT_TESTS=OFF

OPTIONS_DEFINE=	DOCS

pre-install:
	${MV} ${STAGEDIR}/${CONFIGURE_WRKSRC}/stage ${CONFIGURE_WRKSRC}/
	${RM} -r ${STAGEDIR}/wrkdirs

post-install:
.for l in bin/citnames bin/intercept lib/bear/libexec.so lib/bear/wrapper
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${l}
.endfor

.include <bsd.port.mk>
