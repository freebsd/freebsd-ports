# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION=	0.11.0
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		http://static.rust-lang.org/stage0-snapshots/:boot
DISTFILES=	${RUST_SOURCE}:src \
		${RUST_BOOT}:boot
EXTRACT_ONLY=	${RUST_SOURCE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language with a focus on memory safety and concurrency

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE \
		${WRKSRC}/LICENSE-MIT

RUST_SOURCE=	${DISTNAME}${EXTRACT_SUFX}
RUST_BOOT=	rust-stage0-${RUST_BOOT_SIG}.tar.bz2
RUST_BOOT_SIG=	2014-06-21-db9af1d-freebsd-x86_64-ef2bd0fc0b0efa2bd6f5c1eaa60a2ec8df533254
RUST_TARGET=	x86_64-unknown-freebsd

ONLY_FOR_ARCHS=	amd64
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake perl5
USE_PERL5=	build
USE_PYTHON=	yes
USE_PYTHON_BUILD=	2

OPTIONS_DEFINE=		LLNEXTGEN
LLNEXTGEN_DESC=		Build with grammar verification

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		Only compiles on FreeBSD 10 and 11
.endif

.if ${PORT_OPTIONS:MLLNEXTGEN}
BUILD_DEPENDS+=	LLnextgen:${PORTSDIR}/devel/llnextgen
.endif

CC=		clang
CXX=		clang++
CONFIGURE_ARGS+=	--disable-valgrind --disable-docs \
			--enable-clang --mandir=${MANPREFIX}/man
MAKE_ARGS+=		CC="${CC}" CXX="${CXX}" ARCH=x86_64

post-extract:
	${MKDIR} ${WRKSRC}/${RUST_TARGET} && \
	cd ${WRKSRC}/${RUST_TARGET} && \
	${TAR} -xf ${DISTDIR}/${RUST_BOOT} && \
	${MV} rust-stage0 stage0

post-patch:
	${REINPLACE_CMD} -e '/get-snapshot.py $$(CFG_BUILD)/d' ${WRKSRC}/mk/stage0.mk

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/manifest
	${STRIP_CMD} `${GREP} -v -e '^@dirrm' -e '^man' -e 'rlib$$' ${PLIST} | ${SED} 's:^:${STAGEDIR}${PREFIX}/:g'`

.include <bsd.port.post.mk>
