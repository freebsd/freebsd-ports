# New ports collection makefile for:	columns
# Date created:				26 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	columns
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.phreax.net/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl

ALL_TARGET=	# empty

USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/columns ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/columns
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${PREFIX}/share/columns
	${INSTALL_DATA} ${WRKSRC}/*.ofn ${PREFIX}/share/columns
	${INSTALL_DATA} ${WRKSRC}/*.wav ${PREFIX}/share/columns
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/columns
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/columns
.endif

.include <bsd.port.mk>
