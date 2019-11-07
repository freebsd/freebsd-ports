# $FreeBSD$

PORTNAME=	svgbob
DISTVERSION=	g20190412
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Convert ASCII diagrams to SVG

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC:H}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ivanceras
GH_TAGNAME=	c3e84c87094550d8cdc6fc48b40a00712b2951cb

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		cfg-if-0.1.5 \
		clap-2.32.0 \
		handlebars-0.21.1 \
		libc-0.2.60 \
		log-0.3.9 \
		log-0.4.5 \
		pest-0.3.3 \
		pom-1.1.0 \
		quick-error-1.2.2 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		rustc-serialize-0.3.24 \
		strsim-0.7.0 \
		svg-0.5.11 \
		svgbob-0.4.1 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		unicode-width-0.1.5 \
		vec_map-0.8.1 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

# ignore #![deny(warnings)]
RUSTFLAGS+=	--cap-lints warn

WRKSRC_SUBDIR=	svgbob_cli

PLIST_FILES=	bin/svgbob
PORTDOCS=	README.md spec.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/svgbob

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC:H} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
