# $FreeBSD$

PORTNAME=		crystal
DISTVERSION=		0.32.1
CATEGORIES=		lang
MASTER_SITES=		https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/crystal/:bootstrap
DISTFILES=		${BOOTSTRAP_PATH}:bootstrap
DIST_SUBDIR=		${PORTNAME}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Language with Ruby-like syntax and static type checking

LICENSE=	APACHE20

IGNORE_FreeBSD_11=	prebuilt bootstrap only built for FreeBSD >=12 (ino64)
ONLY_FOR_ARCHS=			aarch64 amd64
ONLY_FOR_ARCHS_REASON=		requires prebuilt bootstrap compiler

LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded \
		libevent.so:devel/libevent \
		libpcre.so:devel/pcre \
		libLLVM-${LLVM_VERSION:C/([1-9])([0-9])/\1/}.so:devel/llvm${LLVM_VERSION}
BUILD_DEPENDS=	${LOCALBASE}/bin/llvm-config${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

USES=		compiler gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	crystal-lang

LLVM_VERSION=	90
BOOTSTRAP_PATH=	crystal-${BOOTSTRAP_VER}-freebsd12-${ARCH}
BOOTSTRAP_VER?=	0.32.1

MAKE_ARGS=	SHELL=sh \
		LLVM_CONFIG="${LOCALBASE}/bin/llvm-config${LLVM_VERSION}" \
		FLAGS="--release --no-debug --progress --threads=${MAKE_JOBS_NUMBER}" \
		EXPORTS='CRYSTAL_CONFIG_PATH="lib:${PREFIX}/lib/${PORTNAME}"' \
		CRYSTAL_CACHE_DIR="${WRKDIR}/cache" \
		CRYSTAL_CONFIG_VERSION="${DISTVERSION}"

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

post-extract:
	${MKDIR} ${WRKSRC}/.build
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${BOOTSTRAP_PATH} ${WRKSRC}/.build/crystal
	${CHMOD} +x ${WRKSRC}/.build/crystal
	${LN} -s x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-portbld-freebsd
	${LN} -s x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-freebsd

do-build-DOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} docs \
			CRYSTAL_CACHE_DIR="${WRKDIR}/cache"

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/.build/crystal ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${INSTALL_WRKSRC}/man/crystal.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	(cd ${INSTALL_WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/${PORTNAME})

do-install-DOCS-on:
	(cd ${INSTALL_WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	(cd ${INSTALL_WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

do-install-BASH-on:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/bash_completion.d
	${INSTALL_DATA} ${INSTALL_WRKSRC}/etc/completion.bash \
			${STAGEDIR}${LOCALBASE}/etc/bash_completion.d/_crystal.bash

do-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/zsh/site-functions
	${INSTALL_DATA} ${INSTALL_WRKSRC}/etc/completion.zsh \
			${STAGEDIR}${LOCALBASE}/share/zsh/site-functions/_crystal

.include <bsd.port.mk>
