# New ports collection makefile for:	REXX/imc
# Version required:			1.6d
# Date created:				Septermber 21 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	rexx-imc-1.6d
CATEGORIES+=	lang
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
.ifndef(NOPORTDOCS)
		@ ${MKDIR} -p ${PREFIX}/share/doc/rexx-imc/
		@ for file in README README.avail README.bugreport README.docs README.files README.make README.news README.versions rexx.info rexx.ref rexx.summary rexx.tech; do \
			${INSTALL_DATA} ${WRKDIR}/$$file ${PREFIX}/share/doc/rexx-imc/; \
		done
.endif		

post-install:
		@ ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
