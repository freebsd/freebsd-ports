PORTNAME=	computelibrary
DISTVERSIONPREFIX=	v
DISTVERSION=	53.3.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Arm compute library
WWW=		https://github.com/ARM-software/ComputeLibrary

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

ONLY_FOR_ARCHS=	aarch64 amd64 armv7

TEST_DEPENDS=	scons:devel/scons

USES=		scons
USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_PROJECT=	ComputeLibrary
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

SCONS_ARGS_amd64=	neon=0 opencl=1 examples=0 arch=x86_64
SCONS_ARGS_aarch64=	neon=1 opencl=0 examples=0 arch=arm64-v8a
SCONS_ARGS_armv7=	neon=1 opencl=0 examples=0 arch=armv7a
SCONS_ARGS=		os=freebsd Werror=0 embed_kernels=0 build=native \
			${SCONS_ARGS_${ARCH}}
MAKE_ARGS=		${SCONS_ARGS}
TEST_TARGET=		test

do-install:
.for dir in arm_compute support utils
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/include/${PORTNAME})
.endfor
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME} "-name *.h -name *.hpp")
	${INSTALL_LIB} ${WRKSRC}/build/libarm_compute.so \
		${STAGEDIR}${PREFIX}/lib/libarm_compute.so
	${INSTALL_LIB} ${WRKSRC}/build/libarm_compute_graph.so \
		${STAGEDIR}${PREFIX}/lib/libarm_compute_graph.so
	${INSTALL_DATA} ${WRKSRC}/build/*.a ${STAGEDIR}${PREFIX}/lib

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} scons ${SCONS_ARGS}

.include <bsd.port.post.mk>
