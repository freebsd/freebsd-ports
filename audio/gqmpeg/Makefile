# New ports collection makefile for:	gqmpeg
# Version required:	0.4.6
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.10 1999/02/02 17:07:22 vanilla Exp $
#

DISTNAME=	gqmpeg-0.4.6
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	Imlib.3:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
ALL_TARGET=	gqmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqmpeg ${PREFIX}/bin

.include <bsd.port.mk>
