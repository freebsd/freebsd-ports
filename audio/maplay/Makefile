# New ports collection makefile for:    maplay
# Version required:     1.2
# Date created:         Feb 13 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.2 1995/04/01 12:43:49 jkh Exp $
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
CATEGORIES+=	audio
MASTER_SITES=   ftp://ftp.iuma.com/audio_utils/mpeg_players/Workstations/
EXTRACT_SUFX=	.tar.Z

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; make pre-install)

.include <bsd.port.mk>
