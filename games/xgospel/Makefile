# New ports collection makefile for:	xgospel
# Date created:        13 November 2001
# Whom:                Shao Zhang <shaoz@asia.com>
#
# $FreeBSD$

PORTNAME=	xgospel
PORTVERSION=	1.12d
CATEGORIES=	games
MASTER_SITES=	http://www.teaser.fr/~jlgailly/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 Go (weiqi, baduk) client for the Internet Go Server

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XLIB=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--with-x --with-xpm --with-xaw3d

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,#ifndef _POSIX_SOURCE,#if 0," \
		${WRKSRC}/connect.c ${WRKSRC}/relay.c ${WRKSRC}/relog.c \
		${WRKSRC}/rport.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/relay ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rport ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xgospel ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/board.xpm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pagoda.xpm ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/FAQ ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
