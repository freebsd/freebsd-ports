PORTNAME=	libansilove
PORTVERSION=	1.2.8
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library for converting ANSI, ASCII, and other formats to PNG

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd

USE_GITHUB=	yes
GH_ACCOUNT=	ansilove

USES=		cmake
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTDOCS=	AUTHORS ChangeLog README.md THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
