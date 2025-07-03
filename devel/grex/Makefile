PORTNAME=	grex
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.5
PORTREVISION=	11
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command-line tool for generating regular expressions from test cases
WWW=		https://github.com/pemistahl/grex/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	pemistahl

PLIST_FILES=	bin/grex
PORTDOCS=	README.md RELEASE_NOTES.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
