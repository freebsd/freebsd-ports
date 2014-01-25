# Created by: krion
# $FreeBSD$

PORTNAME=	aewan
PORTVERSION=	1.0.01
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based program for the creation and editing of ASCII art

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	bin/aecat bin/aewan bin/aemakeflic \
		man/man1/aecat.1.gz \
		man/man1/aewan.1.gz \
		man/man1/aemakeflic.1.gz \
		man/man5/aewan.5.gz

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|OSTYPE == |OSTYPE = |g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
