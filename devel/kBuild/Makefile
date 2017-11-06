# Created by: Bruce Simpson
# $FreeBSD$

PORTNAME=	kBuild
DISTVERSION=	${KBUILD_VERSION}
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	LOCAL/jkim
DISTNAME=	${PORTNAME}-${DISTVERSION}r3050-src

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	Makefile framework

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	multi

BROKEN_powerpc64=	does not build: fatal error: xmmintrin.h: No such file or directory
NOT_FOR_ARCHS=		aarch64 armv6 mips mips64
NOT_FOR_ARCHS_REASON=	./kBuild/env.sh: unknown cpu/arch

USE_GCC=	any
USES=		autoreconf:build gmake makeinfo tar:xz

CONFLICTS_INSTALL=	kBuild-devel-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

KBUILD_VERSION=	0.1.9998
KBUILD_ARCH=	${MACHINE_ARCH:S/i386/x86/:S/x86_64/amd64/:S/powerpc/ppc32/:S/armv6/arm/}
KBUILD_ENV=	ACLOCAL=${ACLOCAL} \
		AUTOMAKE=${AUTOMAKE} \
		AUTORECONF=${AUTORECONF} \
		AUTOPOINT=true \
		CFLAGS="-D_WITH_GETLINE -D_WITH_DPRINTF"
KBUILD_TARGET=	${OPSYS:tl}

KBUILD_BINS=	kDepIDB kDepObj kDepPre kObjCache kmk kmk_append kmk_ash \
		kmk_cat kmk_chmod kmk_cmp kmk_cp kmk_echo kmk_expr kmk_gmake \
		kmk_install kmk_ln kmk_md5sum kmk_mkdir kmk_mv kmk_printf \
		kmk_redirect kmk_rm kmk_rmdir kmk_sed kmk_sleep kmk_test \
		kmk_time
PORTDOCS=	QuickReference-kmk.html \
		QuickReference-kmk.txt

ENV=
.export ENV

OPTIONS_DEFINE=	DOCS

post-patch:
	for f in ${WRKSRC}/kBuild/tools/*.kmk; do \
		${REINPLACE_CMD} -e 's|gcc|${CC}|g' $$f ; \
	done

do-build:
	cd ${WRKSRC} && ${SETENV} ${KBUILD_ENV} ./kBuild/env.sh --full ${MAKE_CMD} -f bootstrap.gmk
	cd ${WRKSRC} && ${RM} -r out
	cd ${WRKSRC} && ./kBuild/env.sh kmk
	cd ${WRKSRC} && ./kBuild/env.sh kmk NIX_INSTALL_DIR=${PREFIX} BUILD_TYPE=release -C ${WRKSRC}

do-install:
.for bin in ${KBUILD_BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_ARCH}/release/stage${PREFIX}/bin/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_ARCH}/release/stage${PREFIX}/share/kBuild && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_ARCH}/release/stage${PREFIX}/share/doc/${PORTNAME}-${KBUILD_VERSION}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
