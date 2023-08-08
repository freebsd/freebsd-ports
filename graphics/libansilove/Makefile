PORTNAME=	libansilove
PORTVERSION=	1.4.1
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library for converting ANSI, ASCII, and other formats to PNG
WWW=		https://www.ansilove.org/ \
		https://github.com/ansilove/libansilove

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd

USE_GITHUB=	yes
GH_ACCOUNT=	ansilove

USES=		cpe cmake
USE_LDCONFIG=	yes

CPE_VENDOR=	ansilove

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTDOCS=	AUTHORS ChangeLog README.md THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
