# Created by: refugee
# $FreeBSD$

PORTNAME=	dungeoncrawl
PORTVERSION=	4.0.0.b26
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.dungeoncrawl.org/dev/4.0.x/src/ \
		http://www.sourcefiles.org/Games/Role_Play/
DISTNAME=	dc${PORTVERSION:S/.//g}-src
EXTRACT_SUFX=	.tbz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old school roguelike game

WRKSRC_SUBDIR=	source

USES=		ncurses tar:bzip2
MAKEFILE=	makefile.bsd

PORTDOCS=	buglist.txt crawl.txt
PLIST_FILES=	bin/dungeoncrawl man/man6/dungeoncrawl.6.gz

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
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} crawl \
		${STAGEDIR}${PREFIX}/bin/dungeoncrawl)
	(cd ${WRKSRC}/../docs && ${INSTALL_MAN} crawl.6 \
		${STAGEDIR}${MANPREFIX}/man/man6/dungeoncrawl.6)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	(cd ${WRKSRC}/../docs && ${INSTALL_DATA} ${doc} \
		${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
