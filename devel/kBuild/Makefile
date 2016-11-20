# Created by: Bruce Simpson
# $FreeBSD$

PORTNAME=	kBuild
DISTVERSION=	${KBUILD_VERSION}
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlabs.org/pub/kbuild/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/
DISTNAME=	${PORTNAME}-${DISTVERSION}r2695-src

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	Makefile framework

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USE_GCC=	any
USES=		autoreconf:build gmake makeinfo

CONFLICTS_INSTALL=	kBuild-devel-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

KBUILD_VERSION=	0.1.9998
KBUILD_ARCH=	${MACHINE_ARCH:S/i386/x86/:S/x86_64/amd64/:S/powerpc/ppc32/}
KBUILD_ENV=	ACLOCAL=${ACLOCAL} \
		AUTOMAKE=${AUTOMAKE} \
		AUTORECONF=${AUTORECONF} \
		AUTOPOINT=true \
		CFLAGS="-D_WITH_GETLINE -D_WITH_DPRINTF"
KBUILD_TARGET=	${OPSYS:tl}

KBUILD_BINS=	kDepIDB kDepPre kObjCache kmk kmk_append kmk_ash kmk_cat \
		kmk_chmod kmk_cmp kmk_cp kmk_echo kmk_expr kmk_gmake \
		kmk_install kmk_ln kmk_md5sum kmk_mkdir kmk_mv kmk_printf \
		kmk_redirect kmk_rm kmk_rmdir kmk_sed kmk_sleep kmk_test kmk_time
PORTDOCS=	QuickReference-kmk.html \
		QuickReference-kmk.txt

# bmake doesn't know about unsetenv=true
.if defined(.PARSEDIR)
ENV=
.export ENV
.else
.SHELL:		path="/bin/sh" unsetenv=true
.endif

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '11269d;11274d' ${WRKSRC}/src/sed/configure
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Config.kmk
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
