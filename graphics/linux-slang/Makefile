PORTNAME=	slang
DISTVERSIONPREFIX=	v
DISTVERSION=	2026.18.2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/shader-slang/slang/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux-${ARCH:S,amd64,x86_64,}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Making it easier to work with shaders (Linux release)
WWW=		https://shader-slang.com/

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE BSL CC-BY-4.0 CC0-1.0 GPLv3 \
		LLVM_EXCEPTION MIT NCSA UNLICENSE
LICENSE_COMB=	multi
LICENSE_NAME_LLVM_EXCEPTION=	LLVM Exceptions to the Apache 2.0 License
LICENSE_FILE_LLVM_EXCEPTION=	${WRKSRC}/LICENSES/LLVM-exception.txt
LICENSE_PERMS_LLVM_EXCEPTION=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		linux:rl9
USE_LINUX=	base

CONFLICTS_INSTALL=	libslang2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DISTINFO_FILE=	${.CURDIR}/distinfo.${ARCH}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC}/bin && \
		${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin)
.for dir in include lib share/slang
	(cd ${WRKSRC}/${dir} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${dir})
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/share/doc/slang && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
