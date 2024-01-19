PORTNAME=	dungeoncrawl
PORTVERSION=	4.0.0.b26
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.dungeoncrawl.org/dev/4.0.x/src/ \
		http://www.sourcefiles.org/Games/Role_Play/
DISTNAME=	dc${PORTVERSION:S/.//g}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old school roguelike game
WWW=		http://www.dungeoncrawl.org/

WRKSRC_SUBDIR=	source

USES=		ncurses tar:tbz2
USE_CXXSTD=	gnu++98
CXXFLAGS+=	-fsigned-char
MAKEFILE=	makefile.bsd

PORTDOCS=	buglist.txt crawl.txt
PLIST_FILES=	bin/dungeoncrawl share/man/man6/dungeoncrawl.6.gz

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
		${STAGEDIR}${PREFIX}/share/man/man6/dungeoncrawl.6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/../docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
