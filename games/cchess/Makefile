# New ports collection makefile for:	cchess
# Date created:				10 May 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cchess
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://local-distfiles.freebsd.org.cn/pub/china-ports/hamigua/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very simple Chinese chess program

LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro \
		lirc_client.2:${PORTSDIR}/comms/lirc

USE_GMAKE=	yes

SYSCONFDIR=	${PREFIX}/etc/cchess

post-patch:
	@${REINPLACE_CMD} -e 's|qizi.bmp|${DATADIR}/qizi.bmp|' \
		-e 's|xqbg.bmp|${DATADIR}/xqbg.bmp|' \
		-e 's|BOOK.DAT|${DATADIR}/BOOK.DAT|' \
		-e 's|big.dat|${DATADIR}/big.dat|' \
		-e 's|jiang.wav|${DATADIR}/jiang.wav|' \
	       	${WRKSRC}/src/main.cpp
	@${REINPLACE_CMD} -e 's|sdklircrc|${SYSCONFDIR}/sdklircrc|' \
		${WRKSRC}/src/aihomesdk.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cchess ${LOCALBASE}/bin
	${MKDIR} ${SYSCONFDIR}
	${INSTALL_DATA} ${WRKSRC}/sdklircrc ${SYSCONFDIR}/sdklircrc.sample
	if [ ! -f ${SYSCONFDIR}/sdklircrc ]; then \
		${INSTALL_DATA} ${WRKSRC}/sdklircrc ${SYSCONFDIR}; \
	fi
	${MKDIR} ${DATADIR}
.for i in BOOK.DAT jiang.wav big.dat qizi.bmp xqbg.bmp
	${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}
.endfor

.include <bsd.port.mk>
