# New ports collection makefile for: rust
# Date created: 2012-01-21
# Whom: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	rust
PORTVERSION=	0.1
CATEGORIES=	lang
MASTER_SITES=	http://dl.rust-lang.org/dist/:source \
		http://people.cs.nctu.edu.tw/~jyyou/rust/:boot
DISTFILES=	${RUST_SOURCE}:source \
		${RUST_BOOT}:boot
EXTRACT_ONLY=	${RUST_SOURCE}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language with a focus on memory safety and concurrency

OPTIONS=	CARGO	"Build with package manager" off

RUST_SOURCE=	${DISTNAME}${EXTRACT_SUFX}
RUST_BOOT=	rust-${PORTVERSION}-boot.tar.bz2
RUST_TARGET=	x86_64-unknown-freebsd

ONLY_FOR_ARCHS=	amd64
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_PYTHON_BUILD=	2.6-2.7

MAN1=		rustc.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900044
LIB_DEPENDS+=	unwind.8:${PORTSDIR}/devel/libunwind
CC=		clang
CXX=		clang++
CONFIGURE_ARGS+=	--enable-clang
.else
USE_GCC=	4.4+
.endif

.if ${OSVERSION} < 800107
IGNORE=	needs tgammaf(3)
.endif

.if !defined(WITHOUT_CARGO)
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl \
		git:${PORTSDIR}/devel/git \
		gpg:${PORTSDIR}/security/gnupg
.endif

LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo

MAKE_ARGS+=		CC=${CC} CXX=${CXX} ARCH=x86_64
CONFIGURE_ARGS+=	--disable-valgrind --disable-docs

post-extract:
	${MKDIR} ${WRKSRC}/${RUST_TARGET} && \
	cd ${WRKSRC}/${RUST_TARGET} && \
	    tar xf ${DISTDIR}/${RUST_BOOT} && \
	    ${MV} rust-stage0 stage0

post-patch:
	${REINPLACE_CMD} \
	    -e '/src\/etc\/get-snapshot.py $$(CFG_HOST_TRIPLE)/d' \
	    ${WRKSRC}/mk/stage0.mk
	${REINPLACE_CMD} \
	    -e 's|\$$(PREFIX_ROOT)/share/man|${MANPREFIX}/man|g' \
	    ${WRKSRC}/mk/install.mk

.include <bsd.port.post.mk>
