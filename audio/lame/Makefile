# ports collection makefile for:   lame
# Version required:    2.1f
# Date created:         November 1998
# Whom:                yoshiaki Uchikawa
#
# $Id:$
#

DISTNAME=	dist10
PKGNAME=	lamer-2.1f
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tnt.uni-hannover.de/pub/MPEG/audio/mpeg2/software/technical_report/ \
		ftp://ftp.deva.net/pub/sources/sound/codecs/mpeg/

PATCH_SITES=	http://student.uq.edu.au/~s302585/lame/files/
PATCHFILES=	dist10patch-2.1f.gz

MAINTAINER=	yoshiaki@kt.rim.or.jp

PATCH_DIST_STRIP = -p1

WRKSRC=		${WRKDIR}/dist10/lsf/encoder/
USE_GMAKE=	YES
ALL_TARGET=	lamer
RESTRICTED=	Condition is not clear

do-install:
	( cd ${WRKSRC}; ${INSTALL_PROGRAM} lamer ${PREFIX}/bin )

.include <bsd.port.mk>
