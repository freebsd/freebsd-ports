# New ports collection makefile for:	libshhmsg
# Date created:				1 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	libshhmsg
PORTVERSION=	1.4.0
CATEGORIES=	devel
MASTER_SITES=   http://home.sol.no/~sverrehu/pub-unix/files/
DISTNAME=	shhmsg-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/libshhmsg
.for file in CREDITS README shhmsg.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/libshhmsg
.endfor
.endif

.include <bsd.port.mk>
