# New ports collection makefile for:	Hermes
# Date created:				29 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	Hermes
PORTVERSION=	1.3.1
CATEGORIES=	graphics
MASTER_SITES=	http://tzo.linux.tucows.com/files/x11/dev/ \
		http://oarnet.linux.tucows.com/files/x11/dev/ \
		ftp://ftp.infomagic.com/pub/mirrors/tucows/mlinux/files/x11/dev/ \
		http://dark.x.dtu.dk/~mbn/clanlib/download/

MAINTAINER=	will@FreeBSD.org

USE_LIBTOOL=	yes
USE_GMAKE=	yes

post-install:
	@ ${LN} -sf libHermes.so.1 ${PREFIX}/lib/libHermes.so
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/Hermes
.for file in AUTHORS ChangeLog COPYING FAQ README TODO TODO.conversion
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/Hermes
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/Hermes/API
.for file in api-1.htm api-2.htm api-3.htm api-4.htm api.htm api.ps api.txt
	@ ${INSTALL_DATA} ${WRKSRC}/docs/api/${file} ${PREFIX}/share/doc/Hermes/API
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/docs/api/sgml/api.sgml ${PREFIX}/share/doc/Hermes/API
.endif
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
