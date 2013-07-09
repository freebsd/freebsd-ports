# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION=	0.7
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		http://static.rust-lang.org/stage0-snapshots/:boot
DISTFILES=	${RUST_SOURCE}:src \
		${RUST_BOOT}:boot
EXTRACT_ONLY=	${RUST_SOURCE}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language with a focus on memory safety and concurrency

RUST_SOURCE=	${DISTNAME}${EXTRACT_SUFX}
RUST_BOOT=	rust-stage0-${RUST_BOOT_SIG}.tar.bz2
RUST_BOOT_SIG=	2013-06-23-f827561-freebsd-x86_64-a05bdda2d9ec0e66336d81b98bee8a95442a501f
RUST_TARGET=	x86_64-unknown-freebsd

ONLY_FOR_ARCHS=	amd64
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	2.6-2.7

MAN1=	rustc.1

OPTIONS_DEFINE=		RUSTPKG
RUSTPKG_DESC=		Build with package manager
OPTIONS_DEFAULT=	RUSTPKG

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900044
EXTRA_PATCHES+=	${FILESDIR}/log2.patch \
		${FILESDIR}/llvm.patch
.endif

.if ${OSVERSION} >= 900044
LIB_DEPENDS+=	unwind:${PORTSDIR}/devel/libunwind
CC=		clang
CXX=		clang++
CONFIGURE_ARGS+=	--enable-clang
.else
USE_GCC=	yes
.endif

.if ${PORT_OPTIONS:MRUSTPKG}
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
PLIST_SUB+=	RUSTPKG=""
.else
PLIST_SUB+=	RUSTPKG="@comment "
.endif

LIB_DEPENDS+=	execinfo:${PORTSDIR}/devel/libexecinfo

MAKE_ARGS+=		CC=${CC} CXX=${CXX} ARCH=x86_64
CONFIGURE_ARGS+=	--disable-valgrind --disable-docs

post-extract:
	${MKDIR} ${WRKSRC}/${RUST_TARGET} && \
	cd ${WRKSRC}/${RUST_TARGET} && \
	${TAR} -xf ${DISTDIR}/${RUST_BOOT} && \
	${MV} rust-stage0 stage0

post-patch:
	${REINPLACE_CMD} \
	    -e 's|$$(PREFIX_ROOT)/share/man|${MANPREFIX}/man|' \
	    ${WRKSRC}/mk/install.mk
	${REINPLACE_CMD} \
	    -e '/get-snapshot.py $$(CFG_BUILD_TRIPLE)/d' \
	    ${WRKSRC}/mk/stage0.mk
.if empty(PORT_OPTIONS:MRUSTPKG)
	${REINPLACE_CMD} \
	    -e '/$$(Q)$$(call INSTALL,$$(HB2),$$(PHB),rustpkg$$(X_$$(CFG_BUILD_TRIPLE)))/d' \
	    ${WRKSRC}/mk/install.mk
.endif

.include <bsd.port.post.mk>
