# Created by: samm@freebsd.org
# $FreeBSD$

PORTNAME=	libunrar
PORTVERSION=	3.9.10
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	unrarsrc-${PORTVERSION}

MAINTAINER=	samm@freebsd.org
COMMENT=	Library to work with RAR archives

WRKSRC=		${WRKDIR}/unrar

USES=		gmake
MAKEFILE=	makefile.unix
ALL_TARGET=	lib
USE_LDCONFIG=	yes

do-install:
	${INSTALL_LIB} ${WRKSRC}/libunrar.so.3 ${STAGEDIR}${PREFIX}/lib/
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libunrar.so.3 libunrar.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libunrar3
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${STAGEDIR}${PREFIX}/include/libunrar3/dll.hpp

.include <bsd.port.mk>
