PORTNAME=	heme
PORTVERSION=	0.4.2
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small and fast console hex editor for Unix-like systems
WWW=		http://heme.sourceforge.net/

LICENSE=	GPLv2

USES=		ncurses
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
