# New ports collection makefile for:	gqmpeg
# Version required:	0.6.3
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gqmpeg-0.6.3
CATEGORIES=	audio
MASTER_SITES=	http://gqview.netpedia.net/ \
		http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
ALL_TARGET=	gqmpeg

post-install:
	@strip ${PREFIX}/bin/gqmpeg

.include <bsd.port.mk>
