# New ports collection makefile for:	xjumpx
# Date created:				14 August 2001
# Whom:					Tatsuya Kuidoh <cdr@ga.xdsl.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xjumpx
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://fenix.ne.jp/~cdrtk/soft/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved version of xjump

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		xjumpx.1
MANCOMPRESSED=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjumpx ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/X11/xjumpx
	${CHMOD} 777 ${PREFIX}/lib/X11/xjumpx
	${CP} ${WRKSRC}/XJumpX.ad ${PREFIX}/lib/X11/app-defaults/XJumpX
	${INSTALL_MAN} ${WRKSRC}/xjumpx.1 ${PREFIX}/man/man1
	${GZIP_CMD} ${PREFIX}/man/man1/xjumpx.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
