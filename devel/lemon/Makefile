# Ports collection makefile for:  lemon
# Date created:			  June 4, 2001
# Whom:				  Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	lemon
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hwaci.com/sw/lemon/
DISTFILES=	lemon.c lempar.c

MAINTAINER=	mi@aldan.algebra.com

NO_WRKSUBDIR=	YES

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
