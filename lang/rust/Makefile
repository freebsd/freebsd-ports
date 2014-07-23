# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION=	0.11.0
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		http://static.rust-lang.org/stage0-snapshots/:bootstrap
DISTFILES=	${RUST_SOURCE}:src \
		${RUST_BOOT}:bootstrap
EXTRACT_ONLY=	${RUST_SOURCE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language with a focus on memory safety and concurrency

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE \
		${WRKSRC}/LICENSE-MIT

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap compiler

RUST_SOURCE=	${DISTNAME}${EXTRACT_SUFX}
RUST_BOOT=	rust-stage0-${RUST_BOOT_SIG}.tar.bz2
RUST_BOOT_SIG=	2014-06-21-db9af1d-freebsd-x86_64-ef2bd0fc0b0efa2bd6f5c1eaa60a2ec8df533254

USES=		gmake perl5
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-valgrind --disable-docs \
		--enable-clang --mandir=${MANPREFIX}/man
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_PYTHON=	yes
USE_PYTHON_BUILD=	2
MAKE_ARGS=	ARCH=x86_64

.if defined(BATCH) || defined(PACKAGE_BUILDING)
MAKE_ARGS+=	VERBOSE=1
.endif

OPTIONS_DEFINE=		LLNEXTGEN
LLNEXTGEN_DESC=		Build with grammar verification

LLNEXTGEN_BUILD_DEPENDS=	LLnextgen:${PORTSDIR}/devel/llnextgen

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
BROKEN=		Only compiles on FreeBSD 10 and 11
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/dl
	${LN} -sf ${DISTDIR}/${RUST_BOOT} ${WRKSRC}/dl

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/manifest
	@${STRIP_CMD} `${GREP} -v -e '^@dirrm' -e '^man' -e 'rlib$$' \
		${PLIST} | ${SED} 's:^:${STAGEDIR}${PREFIX}/:'`

.include <bsd.port.post.mk>
