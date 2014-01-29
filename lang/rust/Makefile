# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION=	0.8
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
RUST_BOOT_SIG=	2013-09-23-348d844-freebsd-x86_64-8b99ec197e441f013c5ba0788f8bcfa689bfc75e
RUST_TARGET=	x86_64-unknown-freebsd

ONLY_FOR_ARCHS=	amd64
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake perl5
USE_PERL5=	build
USE_PYTHON_BUILD=	2

MAN1=	rust.1 \
	rustc.1 \
	rustdoc.1 \
	rusti.1 \
	rustpkg.1

OPTIONS_DEFINE=		RUSTPKG
RUSTPKG_DESC=		Build with package manager
OPTIONS_DEFAULT=	RUSTPKG

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900044
BROKEN=		Only compiles on 9.0-RELEASE and later
.endif

LIB_DEPENDS+=	unwind:${PORTSDIR}/devel/libunwind
CC=		clang
CXX=		clang++
CONFIGURE_ARGS+=	--enable-clang

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
