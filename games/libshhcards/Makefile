# New ports collection makefile for:	libshhcards
# Version required:			1.0.3
# Date created:				12 April 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.4 1998/10/01 06:08:59 steve Exp $
#

DISTNAME=	shhcards-1.0.3
PKGNAME=	libshhcards-1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.computas.no/users/shh/pub-unix/files/ \
		http://www.freebsd.org/~mph/distfiles/

MAINTAINER=	andy@icc.surw.chel.su

USE_GMAKE=	yes
USE_X_PREFIX=	yes
SOLIB=		libshhcards.so

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
SOVERSION=	1
.else
SOVERSION=	1.1
.endif

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/shhcards.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/${SOLIB}.${SOVERSION} ${PREFIX}/lib
	@ ${LN} -sf ${SOLIB}.${SOVERSION} ${PREFIX}/lib/${SOLIB}
	@ ${MKDIR} ${PREFIX}/share/doc/libshhcards
	@ ${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/libshhcards
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libshhcards
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
