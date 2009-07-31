# New ports collection makefile for:   xlogical
# Date created:        8 August 2007
# Whom:                Aaron Baugher
#
# $FreeBSD$
#

PORTNAME=	xlogical
PORTVERSION=	1.0p8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://changeling.ixionstudios.com/xlogical/downloads/ \
		http://freebsd.portsreview.info/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/-/}

MAINTAINER=	aaron@baugher.biz
COMMENT=	Remake of the classic puzzle game Logical

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes

post-extract:
	${CHMOD} 755 ${WRKSRC}/missing
	${RM} ${WRKSRC}/LICENSE

post-install:
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/[A-Z][A-Z]* ${DOCSDIR}
.endif

.include <bsd.port.mk>
