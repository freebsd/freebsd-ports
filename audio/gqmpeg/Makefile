# New ports collection makefile for:	gqmpeg
# Version required:	0.6.2
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.14 1999/05/29 04:07:41 steve Exp $
#

DISTNAME=	gqmpeg-0.6.2
CATEGORIES=	audio
MASTER_SITES=	http://gqview.netpedia.net/ \
		http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	Imlib.4:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
ALL_TARGET=	gqmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqmpeg ${PREFIX}/bin

.include <bsd.port.mk>
