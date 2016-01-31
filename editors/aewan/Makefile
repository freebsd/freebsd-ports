# Created by: krion
# $FreeBSD$

PORTNAME=	aewan
PORTVERSION=	1.0.01
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based program for the creation and editing of ASCII art

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake ncurses

PLIST_FILES=	bin/aecat bin/aewan bin/aemakeflic \
		man/man1/aecat.1.gz \
		man/man1/aewan.1.gz \
		man/man1/aemakeflic.1.gz \
		man/man5/aewan.5.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|OSTYPE == |OSTYPE = |g' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
