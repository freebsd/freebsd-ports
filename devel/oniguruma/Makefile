PORTNAME=	oniguruma
DISTVERSION=	6.9.10
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/kkos/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	onig-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Regular expressions library compatible with POSIX/GNU/Perl
WWW=		https://github.com/kkos/oniguruma

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe pathfix
CPE_VENDOR=	oniguruma_project
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/onig
EXAMPLESDIR=	${PREFIX}/share/examples/onig

PORTDOCS=	*
PORTEXAMPLES=	*

CMAKE_OFF=	BUILD_TEST
CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_POSIX_API

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_CMAKE_BOOL=	INSTALL_DOCUMENTATION
EXAMPLES_CMAKE_BOOL=	INSTALL_EXAMPLES

.include <bsd.port.mk>
