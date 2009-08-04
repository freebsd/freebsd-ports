# Ports collection makefile for:  lemon
# Date created:			  June 4, 2001
# Whom:				  Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	lemon
PORTVERSION=	1.69
CATEGORIES=	devel
MASTER_SITES=	http://tx97.net/pub/distfiles/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	vmagerya@gmail.com
COMMENT=	An LALR(1) parser generator. Similar in function to yacc and bison

USE_BZIP2=	yes

post-patch:
	${REINPLACE_CMD} -e 's| = pathsearch(.*| = "${DATADIR}/lempar.c";|' \
		${WRKSRC}/lemon.c

do-build:
	cd ${WRKSRC} && ${MAKE} PROG=lemon NOMAN=1 NO_MAN=1 \
		CFLAGS="-g ${CFLAGS}" \
		-f /usr/share/mk/bsd.prog.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemon ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lempar.c ${DATADIR}/

.include <bsd.port.mk>
