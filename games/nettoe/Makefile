PORTNAME=	nettoe
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.c-s.li/ports/ \
		SF

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Tic tac toe game playable over the network

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nettoe man/man6/nettoe.6.gz

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TO-DO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for I in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$I ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
