# New ports collection makefile for:	ac3dev
# Date created:				23 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ac3dec
PORTVERSION=	0.6.1
CATEGORIES=	audio
MASTER_SITES=	http://dara.notbsd.org/~aholtzma/ac3/tarballs/

MAINTAINER=	3d@FreeBSD.org

GNU_CONFIGURE=	yes
USE_NEWGCC=	yes

pre-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ac3dec
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ac3dec/README
.endif

.include <bsd.port.mk>
