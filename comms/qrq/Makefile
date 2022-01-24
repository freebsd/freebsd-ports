PORTNAME=	qrq
PORTVERSION=	0.3.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/qrq/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Morse telegraphy trainer similar to the classic DOS version by DL4MM

LICENSE=	GPLv2

USES=		gmake ncurses shebangfix
USE_CSTD=	c99

SHEBANG_FILES=	qrqscore

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g'  \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/qrq.c

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}	${WRKSRC}/qrq.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
