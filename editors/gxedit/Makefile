# New ports collection makefile for:	gxedit
# Version required:     1.17
# Date created:		01 Jul 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.15 1998/11/04 08:56:21 vanilla Exp $
#

DISTNAME=	GXedit1.17
PKGNAME=	gxedit-1.17
CATEGORIES=	editors
MASTER_SITES=	http://devplanet.fastethernet.net/

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	yes
ALL_TARGET=	gxedit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftp-ls.sh ${PREFIX}/bin

.include <bsd.port.mk>
