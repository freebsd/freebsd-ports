# New ports collection makefile for:	libshhcards
# Version required:			1.0.3
# Date created:				12 April 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/05/02 18:02:43 mph Exp $
#

DISTNAME=	shhcards-1.0.3
PKGNAME=	libshhcards-1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.computas.no/users/shh/pub-unix/files/ \
		http://www.freebsd.org/~mph/distfiles/

MAINTAINER=	andy@icc.surw.chel.su

USE_GMAKE=	yes
USE_X_PREFIX=	yes

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/shhcards.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/libshhcards.so.1.0.3 ${PREFIX}/lib
	@ ln -s ${PREFIX}/lib/libshhcards.so.1.0.3 ${PREFIX}/lib/libshhcards.so
	@ ${MKDIR} ${PREFIX}/share/doc/libshhcards
	@ ${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/libshhcards
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libshhcards

.include <bsd.port.mk>
