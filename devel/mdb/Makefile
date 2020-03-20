# $FreeBSD$

PORTNAME=	mdb
PORTVERSION=	20200319
CATEGORIES=	devel

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Solaris Modular Debugger

LICENSE=	CDDL

USES=		compiler uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	bsdjhb
GH_PROJECT=	illumos-gate
GH_TAGNAME=	8d7364cff1

ONLY_FOR_ARCHS=	amd64

MAKE_ARGS=	WITH_CTF=yes
MAKE_ARGS+=	BINDIR=${PREFIX}/bin
MAKE_ARGS+=	LIBDIR=${PREFIX}/lib
MAKE_ARGS+=	FREEBSD_SRC_DIR=${SRC_BASE}
WRKSRC_SUBDIR=	freebsd/cddl/usr.bin/mdb
CFLAGS+=	-DMDB_PREFIX=\\\"${PREFIX}\\\" -g

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/cddl/compat) || !exists(${SRC_BASE}/sys/cddl/compat)
IGNORE=		requires full source tree with CDDL sources
.endif

.if ${OSVERSION} < 1300015 && ${COMPILER_TYPE} == "clang" && \
    ${COMPILER_VERSION} >= 80
# clang 8 cannot compile due to enum redefinitions in kernel.h
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang70:devel/llvm70
CPP=	${LOCALBASE}/bin/clang-cpp70
CC=	${LOCALBASE}/bin/clang70
CXX=	${LOCALBASE}/bin/clang++70
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/mdb/kvm/${MACHINE_ARCH}

.include <bsd.port.post.mk>
