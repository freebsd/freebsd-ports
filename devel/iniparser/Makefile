# New ports collection makefile for:	iniparser
# Date created:		01 July 2011
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iniparser
PORTVERSION=	3.0
CATEGORIES=	devel
MASTER_SITES=	http://ndevilla.free.fr/iniparser/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A free stand-alone ini file parsing library

USE_LDCONFIG=	yes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/dictionary.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/iniparser.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libiniparser.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libiniparser.so.0 ${PREFIX}/lib
	@${LN} -sf libiniparser.so.0 ${PREFIX}/lib/libiniparser.so

.include <bsd.port.mk>
