# New ports collection makefile for:	kpuzzle
# Date created:				2000-11-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	kpuzzle
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/apps/KDE2.x/games
MAINTAINER=	kde@freebsd.org

USE_KDELIBS_VER=	2
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's|-O2||g' ${WRKSRC}/configure
.for file in highscore.cpp kpuzzleapp.cpp
	@${PERL} -pi -e 's|#include <malloc.h>||g' ${WRKSRC}/kpuzzle/${file}
.endfor
	@${PERL} -pi -e 's|default|en|g' ${WRKSRC}/kpuzzle/doc/en/Makefile.in

.include <bsd.port.mk>
