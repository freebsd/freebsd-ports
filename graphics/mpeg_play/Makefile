# New ports collection makefile for:	mpeg_play
# Date created:		17 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	mpeg_play
PORTVERSION=	2.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-patched-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes
MAN1=		mpeg_play.1

pre-patch:
	${CP} ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	${CP} ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.mk>
