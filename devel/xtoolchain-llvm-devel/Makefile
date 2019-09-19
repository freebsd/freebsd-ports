# $FreeBSD$

PORTNAME=	xtoolchain
.ifndef NO_LLD_LINK
PORTVERSION=	0.1
.else
PORTVERSION=	0.2
.endif
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none
PKGNAMESUFFIX?=	-llvm${LLVM_SUFFIX}

MAINTAINER?=	brooks@FreeBSD.org
COMMENT=	Pre seeded toolchain to cross build FreeBSD base

LLVM_SUFFIX?=	-devel

NO_BUILD=	yes

XCC?=		clang${LLVM_SUFFIX}
XCXX?=		clang++${LLVM_SUFFIX}
XCPP?=		clang-cpp${LLVM_SUFFIX}
XLD?=		${LOCALBASE}/llvm${LLVM_SUFFIX}/bin/ld.lld
X_COMPILER_TYPE?=	clang

RUN_DEPENDS?=	${XCC}:devel/llvm${LLVM_SUFFIX}

SUB_FILES=	xtoolchain.mk
SUB_LIST=	XCC=${XCC} \
		XCXX=${XCXX} \
		XCPP=${XCPP} \
		XLD=${XLD} \
		X_COMPILER_TYPE=${X_COMPILER_TYPE}

PLIST_FILES=	share/toolchains/llvm${LLVM_SUFFIX}.mk
.ifndef NO_LLD_LINK
PLIST_FILES+=	llvm${LLVM_SUFFIX}/bin/ld
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/toolchains/
	@${INSTALL_DATA} ${WRKDIR}/xtoolchain.mk \
		${STAGEDIR}${PREFIX}/share/toolchains/llvm${LLVM_SUFFIX}.mk

.ifndef NO_LLD_LINK
# XXX: would be better to add -fuse-ld=lld to LDFLAGS, but there isn't
# yet a mechansim for that.  Link added here, not in devel/llvm* to avoid
# forcing lld on all users.
post-install:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/llvm${LLVM_SUFFIX}/bin
	@${LN} -s ld.lld ${STAGEDIR}${LOCALBASE}/llvm${LLVM_SUFFIX}/bin/ld
.endif

.include <bsd.port.mk>
