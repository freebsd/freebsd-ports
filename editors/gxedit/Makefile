# New ports collection makefile for:	gxedit
# Version required:     1.07
# Date created:		01 Jul 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.5 1998/07/20 03:17:55 steve Exp $
#

DISTNAME=	GXedit1.07
PKGNAME=	gxedit-1.07
CATEGORIES=	editors
MASTER_SITES=   http://devplanet.fastethernet.net/
EXTRACT_SUFX=	.tar

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS=	gtk\\.1\\.4:${PORTSDIR}/x11/gtk

BROKEN=		fetch

EXTRACT_BEFORE_ARGS= -xf
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin

.include <bsd.port.mk>
