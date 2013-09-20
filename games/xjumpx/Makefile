# Created by: Tatsuya Kuidoh <cdr@ga.xdsl.ne.jp>
# $FreeBSD$

PORTNAME=	xjumpx
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://fenix.ne.jp/~cdrtk/soft/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved version of xjump

MAKE_ENV=	X11BASE=${LOCALBASE}
USE_XORG=	xpm xaw

MAN1=		xjumpx.1
MANCOMPRESSED=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjumpx ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/X11/xjumpx
	${CHMOD} 777 ${PREFIX}/lib/X11/xjumpx
	${CP} ${WRKSRC}/XJumpX.ad ${PREFIX}/lib/X11/app-defaults/XJumpX
	${INSTALL_MAN} ${WRKSRC}/xjumpx.1 ${PREFIX}/man/man1
	${GZIP_CMD} ${PREFIX}/man/man1/xjumpx.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
