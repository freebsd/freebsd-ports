# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iniparser
PORTVERSION=	4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Free stand-alone ini file parsing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
ALL_TARGET=

USE_GITHUB=	yes
GH_ACCOUNT=	ndevilla

PLIST_FILES=	include/dictionary.h include/iniparser.h lib/libiniparser.a \
		lib/libiniparser.so lib/libiniparser.so.0

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/dictionary.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/iniparser.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libiniparser.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libiniparser.so.0 ${STAGEDIR}${PREFIX}/lib
	@${LN} -sf libiniparser.so.0 ${STAGEDIR}${PREFIX}/lib/libiniparser.so

.include <bsd.port.mk>
