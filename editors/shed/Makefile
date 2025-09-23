PORTNAME=	shed
PORTVERSION=	1.17
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple ncurses-based pico-style hex editor
WWW=		https://sourceforge.net/projects/shed/

LICENSE=	GPLv2

USES=		ncurses
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS BUGS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
