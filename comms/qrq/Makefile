# $FreeBSD$

PORTNAME=	qrq
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/qrq/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Morse telegraphy trainer similar to the classic DOS version by DL4MM

LICENSE=	GPLv2

USES=		gmake ncurses shebangfix
SHEBANG_FILES=	qrqscore

post-install:
	${INSTALL_DATA}	${WRKSRC}/qrq.png ${STAGEDIR}${DATADIR}/qrq.png

.include <bsd.port.mk>
