# New ports collection makefile for:    ptkei
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ptkei
PORTVERSION=	1.10
CATEGORIES=	games
MASTER_SITES=	http://www.cse.buffalo.edu/~koconnor/ptkei/download/

MAINTAINER=	darius@dons.net.au

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/ptkei
	${CP} -r ${WRKSRC}/* ${PREFIX}/ptkei
	${SED} -e "s#%%PREFIX%%#${PREFIX}#" <${FILESDIR}/ptkei > ${PREFIX}/bin/ptkei
	${CHMOD} -R 644 ${PREFIX}/ptkei
	${CHMOD} 755 ${PREFIX}/ptkei
	${CHMOD} 755 ${PREFIX}/ptkei/src
	${CHMOD} 755 ${PREFIX}/ptkei/scripts
	${CHMOD} 755 ${PREFIX}/ptkei/doc
	${CHMOD} 755 ${PREFIX}/ptkei/doc/pics
	${CHMOD} 755 ${PREFIX}/bin/ptkei

.include <bsd.port.mk>
