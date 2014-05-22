# $FreeBSD$

PORTNAME=	libsixel
PORTVERSION=	20140422
CATEGORIES=	graphics

MAINTAINER=	sue@iwmt.org
COMMENT=	A encoder/decoder library for DEC SIXEL graphics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	saitoha
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8bd21f7

GNU_CONFIGURE=	yes

PORTDOCS=	README.md

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsixel.so.0
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
