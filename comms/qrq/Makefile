# $FreeBSD$

PORTNAME=	qrq
PORTVERSION=	0.3.2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/qrq/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Morse telegraphy trainer similar to the classic DOS version by DL4MM

LICENSE=	GPLv2

USES=		gmake ncurses shebangfix

SHEBANG_FILES=	qrqscore

post-install:
	${INSTALL_DATA}	${WRKSRC}/qrq.png ${STAGEDIR}${DATADIR}/qrq.png

MAKE_ENV=	DESTDIR=${LOCALBASE}

.include <bsd.port.mk>
