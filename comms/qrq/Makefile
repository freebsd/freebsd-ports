# $FreeBSD$

PORTNAME=	qrq
PORTVERSION=	0.3.1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://fkurz.net/ham/qrq/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Morse telegraphy trainer similar to the classic DOS version by DL4MM

LICENSE=	GPLv2

MAN1=		qrq.1

USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA}	${WRKSRC}/qrq.png ${DATADIR}/qrq.png

.include <bsd.port.mk>
