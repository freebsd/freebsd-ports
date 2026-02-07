PORTNAME=	bsp
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://games.moria.org.uk/doom/bsp/download/ \
		http://files.kyle-evans.net/freebsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Node builder for Doom
WWW=		https://doombsp.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -fomit-frame-pointer|${CFLAGS} &|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bsp.6 ${STAGEDIR}${PREFIX}/share/man/man6

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
