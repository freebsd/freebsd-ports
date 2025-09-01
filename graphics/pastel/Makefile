PORTNAME=	pastel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Command-line tool to generate, analyze, convert and manipulate colors
WWW=		https://github.com/sharkdp/pastel/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

SHEBANG_FILES=	doc/demo-scripts/gradient.sh

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS

DOCS=		doc/colorcheck.md doc/colorcheck.png \
		doc/demo-scripts/gradient.sh doc/pastel.gif README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
