PORTNAME=	uird
PORTVERSION=	1.1
CATEGORIES=	comms
MASTER_SITES=	http://kbinstuff.googlepages.com/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Universal IR Receiver Daemon

USES=		perl5 gmake tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/uird
PORTDOCS=	Documentation

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}\ $${CFLAGS}|; /strip/d' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uird ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
