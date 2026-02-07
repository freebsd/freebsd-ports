PORTNAME=	cuetools
DISTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Utilities for working with CUE and TOC files
WWW=		https://github.com/svend/cuetools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

USE_GITHUB=	yes
GH_ACCOUNT=	svend

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
