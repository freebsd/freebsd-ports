# New ports collection makefile for:    maplay
# Version required:     1.2
# Date created:         Feb 13 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.1.1.1 1995/02/14 08:32:41 jkh Exp $
#

DISTNAME=       maplay1_2
EXTRACT_SUFX=	.tar.Z
MASTER_SITES=   ftp://ftp.iuma.com/audio_utils/mpeg_players/Workstations/
CATEGORIES+=	audio

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; make pre-install)

.include <bsd.port.mk>
