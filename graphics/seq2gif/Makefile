# $FreeBSD$

PORTNAME=	seq2gif
PORTVERSION=	0.10.4
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	sue@iwmt.org
COMMENT=	Convert a ttyrec record into a gif animation directly

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	saitoha

USE_LDCONFIG=	yes
USES=		libtool

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

PLIST_FILES=	bin/seq2gif

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
