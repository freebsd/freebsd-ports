# New ports collection makefile for:	gqmpeg
# Version required:	0.4.1
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/11/17 00:24:36 asami Exp $
#

DISTNAME=	gqmpeg-0.4.1.src
PKGNAME=	gqmpeg-0.4.1
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Nakai@technologist.com

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		Imlib.1:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/gqmpeg-0.4.1
ALL_TARGET=	gqmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqmpeg ${PREFIX}/bin

.include <bsd.port.mk>
