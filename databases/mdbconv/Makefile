# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mdbconv
PORTVERSION=	1.6
CATEGORIES=	databases
MASTER_SITES=	http://www.handmark.com/downloads/
DISTNAME=	${PORTNAME}freebsd3x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts CSV to MobileDB database

DEPRECATED=	obsolete technology
EXPIRATION_DATE=	2019-09-21

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/mdbconv

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${RM} ${WRKSRC}/mdbconv

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdbconv ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
