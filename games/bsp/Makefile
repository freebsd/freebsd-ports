# Created by: Christian Brueffer <chris@unixpages.org>
# $FreeBSD$

PORTNAME=	bsp
PORTVERSION=	5.2
CATEGORIES=	games
MASTER_SITES=	http://games.moria.org.uk/doom/bsp/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Node builder for Doom

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -fomit-frame-pointer|${CFLAGS} &|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bsp.6 ${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
