PORTNAME=	nInvaders
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	ninvaders-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Space Invaders clone for ncurses
WWW=		http://ninvaders.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl.txt

USES=		ncurses
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" \
		-e "s|^CFLAGS|#CFLAGS|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
