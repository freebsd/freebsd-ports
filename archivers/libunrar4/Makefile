# New ports collection makefile for:    unrar4
# Date created:				30 May 2011
# Whom:					Joris Vandalon
#
# $FreeBSD$
#

PORTNAME=	libunrar4
PORTVERSION=	4.2.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	unrarsrc-${PORTVERSION}

MAINTAINER=	joris@vandalon.nl
COMMENT=	Library to work with RAR archives

WRKSRC=		${WRKDIR}/unrar

USE_GMAKE=	yes
MAKEFILE=	makefile.unix
ALL_TARGET=	lib
USE_LDCONFIG=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libunrar.so ${PREFIX}/lib/libunrar.so.4
	cd ${PREFIX}/lib && ${LN} -sf libunrar.so.4 libunrar.so
	${MKDIR} ${PREFIX}/include/libunrar4
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${PREFIX}/include/libunrar4/dll.hpp

.include <bsd.port.mk>
