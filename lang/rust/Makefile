# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION=	0.9
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		http://static.rust-lang.org/stage0-snapshots/:boot
DISTFILES=	${RUST_SOURCE}:src \
		${RUST_BOOT}:boot
EXTRACT_ONLY=	${RUST_SOURCE}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language with a focus on memory safety and concurrency

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE \
		${WRKSRC}/LICENSE-MIT

RUST_SOURCE=	${DISTNAME}${EXTRACT_SUFX}
RUST_BOOT=	rust-stage0-${RUST_BOOT_SIG}.tar.bz2
RUST_BOOT_SIG=	2014-01-05-a6d3e57-freebsd-x86_64-ac21ea9537da2aaee35b7f3d2698b651dc3e8bd9
RUST_TARGET=	x86_64-unknown-freebsd

ONLY_FOR_ARCHS=	amd64
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake perl5
USE_PERL5=	build
USE_PYTHON_BUILD=	2

MAN1=	rustc.1 \
	rustdoc.1 \
	rustpkg.1

OPTIONS_DEFINE=		RUSTPKG \
			LLNEXTGEN

RUSTPKG_DESC=		Build with package manager
LLNEXTGEN_DESC=		Build with grammar verification
OPTIONS_DEFAULT=	RUSTPKG
OPTIONS_SUB=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900044 || ${OSVERSION} >= 1000000
BROKEN=		Only compiles on FreeBSD 9
.endif

CC=		clang
CXX=		clang++
CONFIGURE_ARGS+=	--disable-valgrind --disable-docs \
			--enable-clang
MAKE_ARGS+=		CC=${CC} CXX=${CXX} ARCH=x86_64

.if ${PORT_OPTIONS:MRUSTPKG}
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
.endif

.if ${PORT_OPTIONS:MLLNEXTGEN}
BUILD_DEPENDS+=	LLnextgen:${PORTSDIR}/devel/llnextgen
.endif

LIB_DEPENDS+=	execinfo:${PORTSDIR}/devel/libexecinfo

post-extract:
	${MKDIR} ${WRKSRC}/${RUST_TARGET} && \
	cd ${WRKSRC}/${RUST_TARGET} && \
	${TAR} -xf ${DISTDIR}/${RUST_BOOT} && \
	${MV} rust-stage0 stage0

post-patch:
	${REINPLACE_CMD} \
	    -e '/get-snapshot.py $$(CFG_BUILD)/d' \
	    ${WRKSRC}/mk/stage0.mk
.if empty(PORT_OPTIONS:MRUSTPKG)
	${REINPLACE_CMD} \
	    -e '/$$(Q)$$(call INSTALL,$$(HB2),$$(PHB),rustpkg$$(X_$$(CFG_BUILD)))/d' \
	    ${WRKSRC}/mk/install.mk
.endif

.include <bsd.port.post.mk>
