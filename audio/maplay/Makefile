# New ports collection makefile for:    maplay
# Version required:     1.2
# Date created:         Feb 13 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.6 1995/02/09 21:03:52 ache Exp $
#

DISTNAME=       maplay1_2
EXTRACT_SUFX=	.tar.Z
MASTER_SITES=   ftp://ftp.iuma.com/audio_utils/mpeg_players/Workstations/
NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; make pre-install)

.include <bsd.port.mk>
