# New ports collection makefile for:	libshhmsg
# Version required:			1.4.0
# Date created:				1 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	shhmsg-1.4.0
PKGNAME=	libshhmsg-1.4.0
CATEGORIES=	devel
MASTER_SITES=   http://home.sol.no/~sverrehu/pub-unix/files/

MAINTAINER=	andy@icc.surw.chel.su

USE_GMAKE=	yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/libshhmsg
.for file in CREDITS README shhmsg.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/libshhmsg
.endfor
.endif

.include <bsd.port.mk>
