# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	ii
PORTVERSION=	1.7
CATEGORIES=	irc
MASTER_SITES=	http://dl.suckless.org/tools/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Minimalist FIFO and filesystem-based IRC client

LICENSE=	MIT

PLIST_FILES=	bin/ii man/man1/ii.1.gz
PORTDOCS=	CHANGES FAQ README
PORTEXAMPLES=	query.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
