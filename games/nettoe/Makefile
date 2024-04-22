PORTNAME=	nettoe
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.c-s.li/ports/ \
		SF

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Tic tac toe game playable over the network
WWW=		http://nettoe.sourceforge.net/

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/nettoe share/man/man6/nettoe.6.gz

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TO-DO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for I in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$I ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
