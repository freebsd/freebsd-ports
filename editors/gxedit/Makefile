# New ports collection makefile for:	gxedit
# Version required:     1.16
# Date created:		01 Jul 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.14 1998/10/24 17:10:14 vanilla Exp $
#

DISTNAME=	GXedit1.16
PKGNAME=	gxedit-1.16
CATEGORIES=	editors
MASTER_SITES=	http://devplanet.fastethernet.net/

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	yes
ALL_TARGET=	gxedit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin

.include <bsd.port.mk>
