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

USES=		gmake

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${STAGEDIR}${PREFIX}|g' \
	-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA}	${WRKSRC}/qrq.png ${STAGEDIR}${DATADIR}/qrq.png

.include <bsd.port.mk>
