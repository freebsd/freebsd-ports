# New ports collection makefile for:	Hermes
# Date created:				29 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	Hermes
PORTVERSION=	1.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Hermes
.for file in AUTHORS ChangeLog FAQ README TODO TODO.conversion
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/Hermes
.endfor
	@${MKDIR} ${PREFIX}/share/doc/Hermes/API
.for file in api-1.htm api-2.htm api-3.htm api-4.htm api.htm api.ps api.txt
	${INSTALL_DATA} ${WRKSRC}/docs/api/${file} ${PREFIX}/share/doc/Hermes/API
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/api/sgml/api.sgml ${PREFIX}/share/doc/Hermes/API
.endif

.include <bsd.port.mk>
