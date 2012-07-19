# New ports collection makefile for: rust
# Date created: 2012-01-21
# Whom: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	rust
PORTVERSION=	0.3
CATEGORIES=	lang
MASTER_SITES=	http://dl.rust-lang.org/dist/:src \
		http://dl.rust-lang.org/stage0-snapshots/:boot
DISTFILES=	${RUST_SOURCE}:src \
		${RUST_BOOT}:boot
EXTRACT_ONLY=	${RUST_SOURCE}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language with a focus on memory safety and concurrency

RUST_SOURCE=	${DISTNAME}${EXTRACT_SUFX}
RUST_BOOT=	rust-stage0-${RUST_BOOT_SIG}.tar.bz2
RUST_BOOT_SIG=	2012-07-06-b5f5676-freebsd-x86_64-926e17746576397c10af9796d30af6a730329f71
RUST_TARGET=	x86_64-unknown-freebsd

ONLY_FOR_ARCHS=	amd64
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	2.6-2.7

MAN1=	rustc.1

OPTIONS_DEFINE=		CARGO
CARGO_DESC=		Build with package manager
OPTIONS_DEFAULT=	CARGO

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900044
LIB_DEPENDS+=	unwind:${PORTSDIR}/devel/libunwind
CC=		clang
CXX=		clang++
CONFIGURE_ARGS+=	--enable-clang
.else
USE_GCC=	4.6+
.endif

.if ${PORT_OPTIONS:MCARGO}
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl \
		git:${PORTSDIR}/devel/git \
		gpg:${PORTSDIR}/security/gnupg
PLIST_SUB+=	CARGO=""
.else
PLIST_SUB+=	CARGO="@comment "
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
	    -e '/probe_need CFG_CURL/d' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} \
	    -e 's|subprocess.call(\["curl"|subprocess.call(["fetch"|' \
	    ${WRKSRC}/src/etc/snapshot.py
	${REINPLACE_CMD} \
	    -e 's|$$(PREFIX_ROOT)/share/man|${MANPREFIX}/man|' \
	    ${WRKSRC}/mk/install.mk
	${REINPLACE_CMD} \
	    -e '/get-snapshot.py $$(CFG_HOST_TRIPLE)/d' \
	    ${WRKSRC}/mk/stage0.mk
.if empty(PORT_OPTIONS:MCARGO)
	${REINPLACE_CMD} \
	    -e '/$$(Q)$$(call INSTALL,$$(HB3),$$(PHB),cargo$$(X))/d' \
	    ${WRKSRC}/mk/install.mk
.endif

.include <bsd.port.post.mk>
