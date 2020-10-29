# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luajit
DISTVERSION=	2.0.5
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	https://luajit.org/download/
DISTNAME=	LuaJIT-${DISTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua

LICENSE=	MIT PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

IGNORE_aarch64=		fails to compile: lj_arch.h:55:2: No support for this architecture (yet)
IGNORE_powerpc64=	fails to compile: lj_arch.h:346:2: No support for PowerPC 64 bit mode

CONFLICTS_INSTALL=	luajit-openresty

WRKSRC=		${WRKDIR}/LuaJIT-${DISTVERSION}
USES=		gmake
USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} CCOPT= CCOPT_x86=

PLIST_SUB+=	VERSION=${DISTVERSION}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} || ${ARCH:Mmips*} || ${ARCH:Msparc*}
USE_GCC=yes
.elif ${ARCH} == amd64
# FreeBSD 12.1 shipped LLVM 8.0.1, which links libluajit with a TLS phdr that
# requests a 16-byte alignment but an offset that's 8 mod 16.  This results in
# hilarity when an error is raised, as luajit raises an exception (stored in a
# static TLS variable) via libunwind.  libunwind assumes proper alignment of
# the exception and uses a movaps instruction, which throws a SIGBUS when it
# encounters this misaligned TLS data.  While the linker problem doesn't seem
# to be specific to amd64, the effect on luajit does seem to be.
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1201000 && ${OSVERSION} < 1202000
LLVM_MINIMUM=	10
BUILD_DEPENDS+=	llvm${LLVM_MINIMUM}>=10.0:devel/llvm${LLVM_MINIMUM}
CC=		clang10
.endif
.endif

post-install:
	${LN} -sf ${PORTNAME}-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
