# New ports collection makefile for:	Hermes
# Date created:				29 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	Hermes
PORTVERSION=	1.2.5
CATEGORIES=	graphics
MASTER_SITES=	http://hermes.terminal.at/files/

MAINTAINER=	will@FreeBSD.org

USE_LIBTOOL=	yes
USE_GMAKE=	yes

post-install:
	@ ${LN} -sf libHermes.so.1 ${PREFIX}/lib/libHermes.so
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/Hermes
.for file in AUTHORS CHANGES COPYING README TODO TODO.conversion
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/Hermes
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${PREFIX}/share/doc/Hermes
	@ ${MKDIR} ${PREFIX}/share/doc/Hermes/API
.for file in api-1.htm api-2.htm api-3.htm api-4.htm api.htm api.ps api.txt
	@ ${INSTALL_DATA} ${WRKSRC}/docs/api/${file} ${PREFIX}/share/doc/Hermes/API
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/docs/api/sgml/api.sgml ${PREFIX}/share/doc/Hermes/API
.endif
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
