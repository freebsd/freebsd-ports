# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iniparser
PORTVERSION=	3.1
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/iniparser/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Free stand-alone ini file parsing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC}
ALL_TARGET=	
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	include/dictionary.h include/iniparser.h lib/libiniparser.a \
		lib/libiniparser.so lib/libiniparser.so.0

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/dictionary.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/iniparser.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libiniparser.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libiniparser.so.0 ${PREFIX}/lib
	@${LN} -sf libiniparser.so.0 ${PREFIX}/lib/libiniparser.so

.include <bsd.port.mk>
