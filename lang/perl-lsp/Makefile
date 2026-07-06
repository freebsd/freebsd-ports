PORTNAME=	perl-lsp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	lang

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Perl language server with deep semantic intelligence
WWW=		https://crates.io/crates/perl-lsp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	tree-sitter-perl

PLIST_FILES=	bin/perl-lsp

.include <bsd.port.mk>
