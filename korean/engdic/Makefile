# Created by: Oh Junseon <hollywar@mail.holywar.net>
# $FreeBSD$

PORTNAME=	engdic
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	korean deskutils
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English dictionary utility for Korean

ALL_TARGET=	clean all
PLIST_FILES=	bin/edic bin/engdic
PORTDATA=	[a-z].dic.gz

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/engdic.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/engdic ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/engdic ${PREFIX}/bin/edic
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/[a-z].dic.gz ${DATADIR}

.include <bsd.port.mk>
