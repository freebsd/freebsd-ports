# New ports collection makefile for:	gxedit
# Version required:     1.05
# Date created:		01 Jul 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.2 1998/07/02 00:11:28 asami Exp $
#

DISTNAME=	GXedit1.05
PKGNAME=	gxedit-1.05
CATEGORIES=	editors
MASTER_SITES=   http://devplanet.fastethernet.net/
EXTRACT_SUFX=	.tar

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk\\.1\\.4:${PORTSDIR}/x11/gtk

EXTRACT_BEFORE_ARGS= -xf
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin

.include <bsd.port.mk>
