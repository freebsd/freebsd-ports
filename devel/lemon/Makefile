# Ports collection makefile for:  lemon
# Date created:			  June 4, 2001
# Whom:				  Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	lemon
PORTVERSION=	1.16
CATEGORIES=	devel
MASTER_SITES=	http://people.FreeBSD.org/~seanc/ports/${PORTNAME}/
DISTFILES=	lemon.c lempar.c

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	An LALR(1) parser generator. Similar in function to yacc and bison

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -p ${DISTDIR}/lemon.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${MAKE} VPATH=${DISTDIR} PROG=lemon NOMAN=1 \
		CFLAGS="${CFLAGS} -DLEMPAR='\"${PREFIX}/share/lemon/lempar.c\"'" \
			-f /usr/share/mk/bsd.prog.mk

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/lemon
	${INSTALL_DATA} ${DISTDIR}/lempar.c ${PREFIX}/share/lemon/

.include <bsd.port.mk>
