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
MASTER_SITES=   http://www.iuma.com/IUMA/ftp/audio_utils/mpeg_players/Workstations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/maplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/maplay
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/maplay
.endif

.include <bsd.port.mk>
