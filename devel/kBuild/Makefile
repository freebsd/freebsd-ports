# Created by: Bruce Simpson
# $FreeBSD$

PORTNAME=	kBuild
DISTVERSION=	${KBUILD_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlabs.org/pub/kbuild/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/
DISTNAME=	${PORTNAME}-${DISTVERSION}r2695-src

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	Makefile framework

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_AUTOTOOLS=	automake autoconf
USES=		gmake

CONFLICTS_INSTALL=	kBuild-devel-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

KBUILD_VERSION=	0.1.9998
KBUILD_ARCH=	${MACHINE_ARCH:S/i386/x86/:S/x86_64/amd64/}
KBUILD_ENV=	ACLOCAL=${ACLOCAL} \
		AUTOMAKE=${AUTOMAKE} \
		AUTORECONF=${AUTORECONF} \
		AUTOPOINT=true
USE_GCC=	any
KBUILD_TARGET=	${OPSYS:L}

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

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e '11269d;11274d' ${WRKSRC}/src/sed/configure
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Config.kmk
	for f in ${WRKSRC}/kBuild/tools/*.kmk; do \
		${REINPLACE_CMD} -e 's|gcc|${CC}|g' $$f ; \
	done

# Override autotools
run-autotools:
do-configure:

do-build:
	cd ${WRKSRC} && ${SETENV} ${KBUILD_ENV} ./kBuild/env.sh --full ${GMAKE} -f bootstrap.gmk
	cd ${WRKSRC} && ${RM} -rf out
	cd ${WRKSRC} && ./kBuild/env.sh kmk
	cd ${WRKSRC} && ./kBuild/env.sh kmk NIX_INSTALL_DIR=${PREFIX} BUILD_TYPE=release -C ${WRKSRC}

do-install:
.for bin in ${KBUILD_BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_ARCH}/release/stage${PREFIX}/bin/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_ARCH}/release/stage${PREFIX}/share/kBuild && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/out/${KBUILD_TARGET}.${KBUILD_ARCH}/release/stage${PREFIX}/share/doc/${PORTNAME}-${KBUILD_VERSION}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc"
BROKEN=		Does not compile on ia64 or powerpc
.endif

.include <bsd.port.post.mk>
