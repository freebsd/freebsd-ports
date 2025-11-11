PORTNAME=	kibi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Tiny text editor written in Rust
WWW=		https://github.com/ilai-deutel/kibi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ilai-deutel

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS SYNTAX
OPTIONS_DEFAULT=	SYNTAX
OPTIONS_SUB=		yes

SYNTAX_DESC=	Install Syntax-highlighting ini files

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/xdg.rs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-SYNTAX-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} syntax.d ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
