# Created by: refugee
# $FreeBSD$

PORTNAME=	dungeoncrawl
PORTVERSION=	4.0.0.b26
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.dungeoncrawl.org/dev/4.0.x/src/ \
		http://www.sourcefiles.org/Games/Role_Play/
DISTNAME=	dc${PORTVERSION:S/.//g}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old school roguelike game

WRKSRC_SUBDIR=	source

USES=		ncurses tar:tbz2
MAKEFILE=	makefile.bsd

PORTDOCS=	buglist.txt crawl.txt
PLIST_FILES=	bin/dungeoncrawl man/man6/dungeoncrawl.6.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXX =|CXX ?=| ; \
		 s|^CFLAGS =|CXXFLAGS +=| ; \
		 s|^LDFLAGS =|# &| ; \
		 s|^INSTALLDIR =|# &| ; \
		 s|^INCLUDES =|# &| ; \
		 s|$$(CFLAGS)|$$(CXXFLAGS)| ; \
		 s|$${CFLAGS}|$${CXXFLAGS}|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crawl \
		${STAGEDIR}${PREFIX}/bin/dungeoncrawl
	${INSTALL_MAN} ${WRKSRC}/../docs/crawl.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/dungeoncrawl.6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/../docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
