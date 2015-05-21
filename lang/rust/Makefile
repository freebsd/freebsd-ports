# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION=	1.0.0
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		http://static.rust-lang.org/stage0-snapshots/:bootstrap
DISTNAME=	${PORTNAME}c-${PORTVERSION}
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

RUST_SOURCE=	${DISTNAME}-src${EXTRACT_SUFX}
RUST_BOOT=	rust-stage0-${RUST_BOOT_SIG}.tar.bz2
RUST_BOOT_SIG=	2015-03-27-5520801-freebsd-x86_64-0910bbad35e213f679d0433884fd51398eb3bc8d

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

.if ${OPSYS} == DragonFly
IGNORE=		please use lang/rust-dragonfly instead
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/dl
	${LN} -sf ${DISTDIR}/${RUST_BOOT} ${WRKSRC}/dl

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/manifest-rustc
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/install.log
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh
	@${STRIP_CMD} `${GREP} -v -e '^@dir' -e '^man' -e 'rlib$$' \
		-e '^.*\.a$$' -e '^.*\.py$$' -e '^%' -e '^.*/rust-gdb$$' \
		-e '^.*rustlib/components$$' -e '^.*/rust-installer-version$$' \
		${PLIST} | ${SED} 's:^:${STAGEDIR}${PREFIX}/:'`

.include <bsd.port.post.mk>
