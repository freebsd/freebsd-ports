# New ports collection makefile for:	gqview
# Version required:	0.5.1
# Date Created:		27 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1999/01/12 16:50:42 vanilla Exp $
#

DISTNAME=	gqview-0.5.1.src
PKGNAME=	gqview-0.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		Imlib.2:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/gqview-0.5.1
ALL_TARGET=	gqview

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqview ${PREFIX}/bin

.include <bsd.port.mk>
