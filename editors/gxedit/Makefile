# New ports collection makefile for:	gxedit
# Version required:     1.04
# Date created:		01 Jul 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id$
#

DISTNAME=	GXedit1.04
PKGNAME=	gxedit-1.04
CATEGORIES=	editors
MASTER_SITES=   http://devplanet.fastethernet.net/
EXTRACT_SUFX=	.tar

MAINTAINER=     dom@myrddin.demon.co.uk

LIB_DEPENDS+=	gtk\\.1\\.4:${PORTSDIR}/x11/gtk

EXTRACT_BEFORE_ARGS= -xf
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxedit ${PREFIX}/bin

.include <bsd.port.mk>
