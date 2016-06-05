# Created by: chinsan
# $FreeBSD$

PORTNAME=	gnake
PORTVERSION=	0.94b
CATEGORIES=	games
MASTER_SITES=	SF/fbsdports/gnake
DISTNAME=	Gnake.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nibbles clone for GNU/Linux and *BSD

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

LDFLAGS+=	-L${LOCALBASE}/lib -lncurses
CFLAGS+=	-Wall

WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/gnake.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
