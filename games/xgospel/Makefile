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

CONFIGURE_ARGS=	--with-x --with-xpm --with-xaw3d

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

.include <bsd.port.mk>
