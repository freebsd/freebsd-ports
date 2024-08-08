PORTNAME=	bear
DISTVERSION=	3.1.3
PORTREVISION=	8
CATEGORIES=	devel

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tool that generates a compilation database for clang tooling
WWW=		https://github.com/rizsotto/Bear

LICENSE=	GPLv3+

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libabsl_hash.so:devel/abseil \
		libfmt.so:devel/libfmt \
		libgrpc.so:devel/grpc \
		libprotobuf.so:devel/protobuf \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rizsotto
GH_PROJECT=	Bear

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR} \
		-DENABLE_FUNC_TESTS=OFF \
		-DENABLE_UNIT_TESTS=OFF

OPTIONS_DEFINE=	DOCS

pre-install:
	${MV} ${STAGEDIR}/${CONFIGURE_WRKSRC}/stage ${CONFIGURE_WRKSRC}/
	${RM} -r ${STAGEDIR}/wrkdirs

post-install:
.for l in bin/bear lib/bear/libexec.so lib/bear/wrapper
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${l}
.endfor

.include <bsd.port.mk>
