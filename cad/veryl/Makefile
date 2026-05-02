PORTNAME=	veryl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Veryl: A modern Hardware Description Language (HDL)
WWW=		https://github.com/dalance/veryl

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dalance

GH_TUPLE=	veryl-lang:discovery:5136c98:discovery/support/discovery \
		veryl-lang:doc:3a50142:doc/doc \
		veryl-lang:rouge:dd795ac:rouge/support/rouge \
		veryl-lang:sourcemap-resolver:380f8c18:sourcemapresolver/support/sourcemap-resolver \
		veryl-lang:tree-sitter-veryl:f38156e:treesitterveryl/support/tree-sitter \
		veryl-lang:veryl.vim:370dac7:verylvim/support/vim

CARGO_INSTALL_PATH=	crates/veryl

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
