# New ports collection makefile for:	corewars
# Date created:			29 February 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	corewars
PORTVERSION=	0.9.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simulation game where the goal is to crash each other's programs

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
MAKE_ENV=	FREEBSD_CFLAGS="${CFLAGS}"

MAN6=		corewars.6

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing README in ${PREFIX}/share/doc/corewars."
	@${ECHO_MSG} "===>   Please read it before playing."
	@${MKDIR} ${PREFIX}/share/doc/corewars && ${CHMOD} a+rx ${PREFIX}/share/doc/corewars
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/corewars
.endif

.include <bsd.port.mk>
