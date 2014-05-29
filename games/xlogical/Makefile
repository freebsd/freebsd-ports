# Created by: Aaron Baugher
# $FreeBSD$

PORTNAME=	xlogical
PORTVERSION=	1.0p8
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://changeling.ixionstudios.com/xlogical/downloads/ \
		http://freebsd.portsreview.info/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/-/}

MAINTAINER=	aaron@baugher.biz
COMMENT=	Remake of the classic puzzle game Logical

USES=		gmake tar:bzip2
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-extract:
	${CHMOD} 755 ${WRKSRC}/missing
	${RM} ${WRKSRC}/LICENSE

post-install:
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/[A-Z][A-Z]* ${DOCSDIR}
.endif

.include <bsd.port.mk>
