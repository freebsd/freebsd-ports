# New ports collection makefile for:	gxedit
# Version required:     1.12
# Date created:		01 Jul 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.10 1998/08/07 23:56:17 asami Exp $
#

DISTNAME=	GXedit1.12
PKGNAME=	gxedit-1.12
CATEGORIES=	editors
MASTER_SITES=	http://devplanet.fastethernet.net/

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk11\\.1\\.:${PORTSDIR}/x11-toolkits/gtk11

USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin

.include <bsd.port.mk>
