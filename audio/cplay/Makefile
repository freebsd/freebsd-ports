# New ports collection makefile for:	cplay
# Date created: 	1 November 2001
# Whom: 		Jochem Kossen
#
# $FreeBSD$
#

PORTNAME=	cplay
PORTVERSION=	1.49
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A curses based front-end for various audio players

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
MAN1=		cplay.1

MAKE_ARGS+=	PREFIX="${PREFIX}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
