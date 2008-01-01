# New ports collection makefile for:   vrml2pov
# Date created:        31 December 2007
# Whom:                Martin Dieringer <dieringe@zedat.fu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	vrml2pov
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.chemicalgraphics.com/paul/vrml2pov/dist/v${PORTVERSION}/
DISTNAME=	vrml2pov-src

MAINTAINER=	dieringe@zedat.fu-berlin.de
COMMENT=	Convert VRML files to POVRay source

RESTRICTED=	Redistribution is not allowed

USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/vrml2pov
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vrml2pov ${PREFIX}/bin

.include <bsd.port.mk>
