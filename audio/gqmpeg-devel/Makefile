# New ports collection makefile for:	gqmpeg
# Version required:	0.4.4
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.7 1999/01/12 16:50:42 vanilla Exp $
#

DISTNAME=	gqmpeg-0.4.4
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel \
		Imlib.2:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	yes
ALL_TARGET=	gqmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqmpeg ${PREFIX}/bin

.include <bsd.port.mk>
