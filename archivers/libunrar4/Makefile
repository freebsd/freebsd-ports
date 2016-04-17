# Created by: Joris Vandalon
# $FreeBSD$

PORTNAME=	libunrar4
PORTVERSION=	4.2.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/
DISTNAME=	unrarsrc-${PORTVERSION}

MAINTAINER=	joris@vandalon.nl
COMMENT=	Library to work with RAR archives

WRKSRC=		${WRKDIR}/unrar

USES=		gmake
MAKE_ARGS=	CC="${CC}" CXX="${CXX}"
MAKEFILE=	makefile.unix
ALL_TARGET=	lib
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_LIB} ${WRKSRC}/libunrar.so ${STAGEDIR}${PREFIX}/lib/libunrar.so.4
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libunrar.so.4 libunrar.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libunrar4
	${INSTALL_DATA} ${WRKSRC}/dll.hpp ${STAGEDIR}${PREFIX}/include/libunrar4/dll.hpp

.include <bsd.port.mk>
