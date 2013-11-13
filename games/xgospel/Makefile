# Created by: Shao Zhang <shaoz@asia.com>
# $FreeBSD$

PORTNAME=	xgospel
PORTVERSION=	1.12d
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://gailly.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 Go (weiqi, baduk) client for the Internet Go Server

LIB_DEPENDS=	libXaw3d.so:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XORG=	ice sm x11 xaw xext xmu xpm xt
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--with-x --with-xpm --with-xaw3d

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s,#ifndef _POSIX_SOURCE,#if 0," \
		${WRKSRC}/connect.c ${WRKSRC}/relay.c ${WRKSRC}/relog.c \
		${WRKSRC}/rport.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/relay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rport ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xgospel ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/board.xpm ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pagoda.xpm ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
