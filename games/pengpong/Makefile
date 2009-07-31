# New ports collection makefile for:	pengpong
# Date created:				Fri Aug 24 18:21:25 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	pengpong
PORTVERSION=	0.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform pong game written in SDL

USE_SDL=	image sdl
NO_WRKSUBDIR=	yes
USE_PERL5_BUILD=yes

DATAFILES=	24P_Copperplate_Blue.png ball.tga logo.jpg \
		paddle.tga red.png

pre-patch:
	@${PERL} -pi.orig -e \
		's|/usr/local/share/games/pengpong|${DATADIR}|' \
		${WRKSRC}/files.h
	@${PERL} -pi.orig -e 's|0.2|${PORTVERSION}|' \
		${WRKSRC}/pengpong.cpp

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/pengpong ${PREFIX}/bin
.for files in ${DATAFILES}
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/${files} ${DATADIR}
.endfor

.include <bsd.port.mk>
