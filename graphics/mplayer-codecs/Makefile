# New ports collection makefile for:	mplayer-codecs
# Date created:		10 August 2001
# Whom:			Thomas E. Zander
#
# $FreeBSD$
#

PORTNAME=	mplayer-codecs
PORTVERSION=	0.18
CATEGORIES=	graphics audio
MASTER_SITES=	http://mp.dev.hu/MPlayer/releases/ \
		http://www.stud.uni-karlsruhe.de/~uedc/mplayer/
DISTNAME=	w32codec-${PORTVERSION}

MAINTAINER=	riggs@rrr.de

RESTRICTED=	Unsure of codec\'s license

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/mplayer-codecs
	@${CHMOD} 0555 ${PREFIX}/lib/mplayer-codecs
	@${INSTALL_DATA} ${WRKDIR}/* ${PREFIX}/lib/mplayer-codecs

.include <bsd.port.mk>
