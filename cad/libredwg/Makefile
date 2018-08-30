# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libredwg
PORTVERSION=	0.6
CATEGORIES=	cad devel
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library and command line tools to handle DWG files

LICENSE=	GPLv3+

USES=		libtool tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		LibreDWG
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
