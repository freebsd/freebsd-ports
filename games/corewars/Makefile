# New ports collection makefile for:	corewars
# Date created:			29 February 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	corewars
PORTVERSION=	0.9.13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simulation game where the goal is to crash each other's programs

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes

MAN6=		corewars.6 corewars-cmd.6

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
