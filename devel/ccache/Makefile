# Created by: Dominic Marks <d.marks@student.umist.ac.uk>
# $FreeBSD$

PORTNAME=	ccache
PORTVERSION=	3.2.5
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.samba.org/ftp/ccache/ \
		LOCAL/bdrewery

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Tool to minimize the compile time of C/C++ programs

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

HOWTO=		ccache-howto-freebsd.txt
CCLINKDIR=	libexec/ccache
SUB_FILES=	${HOWTO} world-ccache pkg-message ccache-update-links.sh

PORTDOCS=	ccache-howto-freebsd.txt MANUAL.html

OPTIONS_DEFINE=	CLANGLINK LLVMLINK STATIC DOCS TINDERBOX
OPTIONS_DEFAULT=CLANGLINK LLVMLINK

CLANGLINK_DESC=	Create clang compiler links if clang is installed
LLVMLINK_DESC=	Create llvm compiler links if llvm is installed
TINDERBOX_DESC=	Create tarball for tinderbox usage

USES=		compiler
# Don't allow autoreconf. We want no dependencies on this to keep
# WITH_CCACHE_BUILD working.
USES:=		${USES:Nautoreconf}

OPTIONS_SUB=	yes

STATIC_LDFLAGS=	-static

.include <bsd.port.pre.mk>

.  if ${COMPILER_TYPE} == clang
CPPFLAGS+=	-DCC_IS_CLANG
.  elif ${COMPILER_TYPE} == gcc
CPPFLAGS+=	-DCC_IS_GCC
.  endif

PLIST_SUB+=	CCLINKDIR="${CCLINKDIR}"

.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif

GNU_COMPILERS+=		34 42 43 44 45 46 47 48 49 5 6
CCACHE_COMPILERS+=	cc c++ CC gcc g++ ${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|}

.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS+=	33 34 35 36 37 38 -devel
CCACHE_COMPILERS+=	clang clang++ ${CLANG_COMPILERS:S|^|clang|} ${CLANG_COMPILERS:S|^|clang++|}
.endif

.if ${PORT_OPTIONS:MLLVMLINK}
CCACHE_COMPILERS+=	llvm-gcc llvm-c++ llvm-g++
.endif

CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
SUB_LIST+=	CCACHE_COMPILERS="${CCACHE_COMPILERS}" \
		CCLINKDIR="${CCLINKDIR}" \
		ICCPREFIX="${LOCALBASE}/intel_cc_80/bin" \
		HOWTO="${HOWTO}"

post-build-TINDERBOX-on:
	@${MKDIR} ${WRKDIR}/tb/opt
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${WRKDIR}/tb/opt
.for l in ${CCACHE_COMPILERS}
	@${LN} -sf ${PORTNAME} ${WRKDIR}/tb/opt/${l}
.endfor
	@${TAR} -C ${WRKDIR}/tb -cpf ${WRKSRC}/${PORTNAME}.tar opt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccache ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ccache.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}/world
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache \
		${STAGEDIR}${PREFIX}/${CCLINKDIR}/world/ccache
	${INSTALL_SCRIPT} ${WRKDIR}/ccache-update-links.sh \
		${STAGEDIR}${PREFIX}/bin/ccache-update-links

do-install-TINDERBOX-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.tar ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${HOWTO} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
