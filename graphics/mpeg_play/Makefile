# New ports collection makefile for:	mpeg_play
# Version required:	2.0
# Date created:		17 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.2 1995/02/11 13:49:32 asami Exp $
#

DISTNAME=	mpeg_play-2.0
USE_IMAKE=	yes
MASTER_SITES=	ftp://s2k-ftp.cs.berkeley.edu/pub/multimedia/mpeg/
MAINTAINER=	asami@FreeBSD.ORG
EXTRACT_SUFX=	.tar.Z
NO_WRKSUBDIR=	yes

pre-patch:
	cp ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	cp ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.mk>
