# New ports collection makefile for:    unrar
# Date created:				23 Sep 2005
# Whom:					samm@os2.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	libunrar
PORTVERSION=	3.9.6
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	unrarsrc-${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Library to work with RAR archivies

WRKSRC=		${WRKDIR}/unrar

USE_GMAKE=	yes
MAKEFILE=	makefile.unix
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
ALL_TARGET=	lib
USE_LDCONFIG=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libunrar.so.3 ${PREFIX}/lib/
	cd ${PREFIX}/lib && ${LN} -sf libunrar.so.3 libunrar.so
	${MKDIR} ${PREFIX}/include/libunrar3
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${PREFIX}/include/libunrar3/dll.hpp

.include <bsd.port.mk>
