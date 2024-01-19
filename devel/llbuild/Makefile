PORTNAME=		llbuild
DISTVERSIONPREFIX=	swift-DEVELOPMENT-
DISTVERSION=		SNAPSHOT-2017-12-10
DISTVERSIONSUFFIX=	-a
CATEGORIES=		devel

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Low-level build system, used by the Swift Package Manager
WWW=		https://github.com/apple/swift-llbuild

LICENSE=	APACHE20 BSD3CLAUSE NCSA
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=		fails to link: undefined symbol: sbrk
BROKEN_riscv64=		fails to link: undefined symbol: sbrk

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	apple
GH_PROJECT=	swift-llbuild

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CONTRIBUTING.md README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
