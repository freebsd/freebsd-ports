# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION=	0.12.0
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
RUST_BOOT_SIG=	2014-10-04-749ff5e-freebsd-x86_64-f39d94487d29b3d48217b1295ad2cda8c941e694

USES=		gmake perl5 python:2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-valgrind --disable-docs \
		--enable-clang --mandir=${MANPREFIX}/man
USE_LDCONFIG=	yes
USE_PERL5=	build
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
	@${STRIP_CMD} `${GREP} -v -e '^@dir' -e '^man' -e 'rlib$$' \
		${PLIST} | ${SED} 's:^:${STAGEDIR}${PREFIX}/:'`
	@${STRIP_CMD} `${GREP} -v -e '^@dir' -e '^man' -e 'rlib$$' \
		-e '\.a$$' ${PLIST} | ${SED} 's:^:${STAGEDIR}${PREFIX}/:g'`

.include <bsd.port.post.mk>
