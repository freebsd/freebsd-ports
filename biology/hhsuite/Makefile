# $FreeBSD$

PORTNAME=	hhsuite
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	biology science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Remote protein homology detection suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openmpi>0:net/openmpi
LIB_DEPENDS=	libomp.so:devel/openmp
RUN_DEPENDS=	openmpi>0:net/openmpi

USES=		cmake compiler:c++11-lang perl5 python shebangfix
SHEBANG_GLOB=	*.pl *.py
USE_GITHUB=	yes
GH_ACCOUNT=	soedinglab
GH_PROJECT=	hh-suite

LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/mpi/openmpi/lib -L${LOCALBASE}/mpi/openmpi/lib -lmpi # force linking to openmpi, and not to mpich

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == powerpc64
CMAKE_ON=	HAVE_SSE2
.endif

.if ${ARCH} == powerpc64
post-patch:
	${REINPLACE_CMD} -e 's/-msse -msse2/-D_ARCH_PWR8 -DNO_WARN_X86_INTRINSICS -maltivec -mpower8-vector -mvsx/g' ${WRKSRC}/src/CMakeLists.txt
.endif

.include <bsd.port.mk>
