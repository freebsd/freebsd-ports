# $FreeBSD$

PORTNAME=	qrq
PORTVERSION=	0.3.3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/qrq/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Morse telegraphy trainer similar to the classic DOS version by DL4MM

LICENSE=	GPLv2

USES=		gmake ncurses shebangfix
USE_CSTD=	c99

SHEBANG_FILES=	qrqscore

post-install:
	${INSTALL_DATA}	${WRKSRC}/qrq.png ${STAGEDIR}${DATADIR}/qrq.png

MAKE_ENV=	DESTDIR=${LOCALBASE}

.include <bsd.port.mk>
