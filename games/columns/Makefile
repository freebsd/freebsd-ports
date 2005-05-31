# New ports collection makefile for:	columns
# Date created:				26 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	columns
PORTVERSION=	1.2b
PORTREVISION=	1
CATEGORIES=	games
# mastersite disappeared in December 2000
MASTER_SITES=	# http://www.rzuser.uni-heidelberg.de/~dheck/columns/
DISTNAME=	Columns-${PORTVERSION}

DEPRECATED=	"no longer available on master site"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice little implementation of columns game for X Window System

USE_SDL=	sdl
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/columns
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/columns
.endif

.include <bsd.port.mk>
