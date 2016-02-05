# Created by: Oh Junseon <hollywar@mail.holywar.net>
# $FreeBSD$

PORTNAME=	engdic
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	korean deskutils
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English dictionary utility for Korean

USES=		ncurses
EXTRACT_AFTER_ARGS=	--exclude '*.o'
MAKE_ARGS=	CC="${CC}" LDADD="-lz ${LDFLAGS} -lncurses"
PLIST_FILES=	bin/edic bin/engdic
PORTDATA=	[a-z].dic.gz

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/engdic.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/engdic ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/engdic ${STAGEDIR}${PREFIX}/bin/edic
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/[a-z].dic.gz ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
