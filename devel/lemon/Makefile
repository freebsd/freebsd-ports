# Ports collection makefile for:  lemon
# Date created:			  June 4, 2001
# Whom:				  Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	lemon
PORTVERSION=	1.33
CATEGORIES=	devel
MASTER_SITES=	http://people.FreeBSD.org/~seanc/ports/${PORTNAME}/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	An LALR(1) parser generator. Similar in function to yacc and bison

USE_BZIP2=	yes

do-build:
	cd ${WRKSRC} && ${MAKE} PROG=lemon NOMAN=1 NO_MAN=1 \
		CFLAGS="-g ${CFLAGS} -DLEMPAR='\"${PREFIX}/share/lemon/lempar.c\"'" \
			-f /usr/share/mk/bsd.prog.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/lemon
	${INSTALL_DATA} ${WRKSRC}/lempar.c ${PREFIX}/share/lemon/

.include <bsd.port.mk>
