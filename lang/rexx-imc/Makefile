# New ports collection makefile for:	REXX/imc
# Version required:			1.6d
# Date created:				Septermber 21 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.3 1997/07/17 15:12:49 max Exp $
#

DISTNAME=	rexx-imc-1.6d
CATEGORIES=	lang
MASTER_SITES=	http://www.comlab.ox.ac.uk/oucl/users/ian.collier/distribution/

MAINTAINER=	jfitz@FreeBSD.ORG

NO_WRKSUBDIR=	YES

pre-build:
		@ ${CP} ${FILESDIR}/Makefile ${WRKDIR}

do-install:
		@strip ${WRKDIR}/librexx.so.1.6.4 ${WRKDIR}/rxmathfn.rxfn
		@ for file in rexx rxque rxstack; do \
			${INSTALL_PROGRAM} ${WRKDIR}/$$file ${PREFIX}/bin; \
		done
		@ for file in rxmathfn.rxfn rxmathfn.rxlib; do \
			${INSTALL_DATA} ${WRKDIR}/$$file ${PREFIX}/bin; \
		done
		@ for file in librexx.a librexx.so.1.6.4; do \
			${INSTALL_DATA} ${WRKDIR}/$$file ${PREFIX}/lib; \
		done
		@(${INSTALL_DATA} ${WRKDIR}/rexxsaa.h ${PREFIX}/include)
.ifndef(NOPORTDOCS)
		@ ${MKDIR} ${PREFIX}/share/doc/rexx-imc/
		@ for file in README README.avail README.bugreport README.docs README.files README.make README.news README.versions rexx.info rexx.ref rexx.summary rexx.tech; do \
			${INSTALL_DATA} ${WRKDIR}/$$file ${PREFIX}/share/doc/rexx-imc/; \
		done
.endif

post-install:
		@ ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
