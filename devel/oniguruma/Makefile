PORTNAME=	oniguruma
DISTVERSION=	6.9.8
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/kkos/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	onig-${DISTVERSION}

PATCH_SITES=	https://github.com/kkos/oniguruma/commit/
PATCHFILES=	1f322c45aa365d377e1d7db567bb7087c7c1b38c.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Regular expressions library compatible with POSIX/GNU/Perl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe pathfix
CPE_VENDOR=	oniguruma_project
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/onig
EXAMPLESDIR=	${PREFIX}/share/examples/onig

PORTDOCS=	*
PORTEXAMPLES=	*

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_POSIX_API

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_CMAKE_BOOL=	INSTALL_DOCUMENTATION
EXAMPLES_CMAKE_BOOL==	INSTALL_EXAMPLES

.include <bsd.port.mk>
