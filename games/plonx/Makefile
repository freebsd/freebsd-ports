# Created by: clive crous <clive@darkarts.co.za>
# $FreeBSD$

PORTNAME=	plonx
PORTVERSION=	0.03
CATEGORIES=	games
MASTER_SITES=	http://bilious.homelinux.org/~paxed/${PORTNAME}/

MAINTAINER=	clive@darkarts.co.za
COMMENT=	Small ASCII puzzle game

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
PLIST_FILES=	bin/plonx
PORTDOCS=	README

LDFLAGS+=	-lncurses

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
