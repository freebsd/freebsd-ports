# New ports collection makefile for:	mpeg_play
# Version required:	2.0
# Date created:		17 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.4 1995/04/01 12:45:54 jkh Exp $
#

DISTNAME=	mpeg_play-2.0
CATEGORIES+=	graphics
MASTER_SITES=	ftp://s2k-ftp.cs.berkeley.edu/pub/multimedia/mpeg/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	asami@FreeBSD.ORG

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

pre-patch:
	cp ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	cp ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.mk>
