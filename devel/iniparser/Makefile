# New ports collection makefile for:	iniparser
# Date created:		01 July 2011
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iniparser
PORTVERSION=	3.1
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/iniparser/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Free stand-alone ini file parsing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	include/dictionary.h include/iniparser.h lib/libiniparser.a \
		lib/libiniparser.so lib/libiniparser.so.0

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/dictionary.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/iniparser.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libiniparser.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libiniparser.so.0 ${PREFIX}/lib
	@${LN} -sf libiniparser.so.0 ${PREFIX}/lib/libiniparser.so

.include <bsd.port.mk>
