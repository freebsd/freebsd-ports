# New ports collection makefile for:	mod_url
# Date created:		13 Apr 2003
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		mod_url
PORTVERSION=		20010905
CATEGORIES=		korean www
MASTER_SITES=		http://kle.kldp.org/apache/
DISTFILES=		${PORTNAME}.c readme.${PORTNAME}

MAINTAINER=		cjh@FreeBSD.org
COMMENT=		Apache module for manipulating euc-kr encoded URL

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS?=			${LOCALBASE}/sbin/apxs
APACHE_PORT?=		${PORTSDIR}/www/apache13

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${_DISTDIR}/${PORTNAME}.c ${_DISTDIR}/readme.mod_url ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${APXS} -c -I${PREFIX}/include -L${PREFIX}/lib -liconv ${PORTNAME}.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.so ${PREFIX}/libexec/apache/
	${MKDIR} ${PREFIX}/share/doc/mod_url
	${INSTALL_DATA} ${WRKSRC}/readme.${PORTNAME} ${PREFIX}/share/doc/mod_url/
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
