# New ports collection makefile for:	gxedit
# Version required:			1.20
# Date created:				01 Jul 1998
# Whom:					Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.17 1999/01/17 20:06:45 vanilla Exp $
#

DISTNAME=	GXedit1.20
PKGNAME=	gxedit-1.20
CATEGORIES=	editors
MASTER_SITES=	http://devplanet.fastethernet.net/

MAINTAINER=	dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel

USE_X_PREFIX=	yes
ALL_TARGET=	gxedit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtk-shell ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp-ls.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp-put.sh ${PREFIX}/bin

.include <bsd.port.mk>
