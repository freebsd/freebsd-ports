PORTNAME=	rainfrog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.16
CATEGORIES=	databases

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Database tool for the terminal
WWW=		https://crates.io/crates/rainfrog

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE BSL CC0-1.0 CDDL ISCL MIT MPL20 \
		UNICODE UNLICENSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	Unicode Terms of Use
LICENSE_TEXT_UNICODE=	See https://spdx.org/licenses/Unicode-TOU.html
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	achristmascarl

PLIST_FILES=	bin/rainfrog
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
