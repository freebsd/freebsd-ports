# New ports collection makefile for:    maplay
# Version required:     1.2
# Date created:         Feb 13 1995
# Whom:                 jkh
#
# $FreeBSD$
#

DISTNAME=       maplay1_2
PKGNAME=	maplay-1.2
CATEGORIES=	audio
MASTER_SITES=   ftp://ftp.iuma.com/audio_utils/mpeg_players/Workstations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p2

pre-configure:
	@(cd ${WRKSRC}; make pre-install)

post-install:
	@${MKDIR} ${PREFIX}/share/doc/maplay
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/maplay

.include <bsd.port.mk>
