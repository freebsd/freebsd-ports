# New ports collection makefile for:  sfio
# Version required:	97
# Date created: 	8 November 1997
# Whom:			jraynard
#
# $Id: Makefile,v 1.3 1997/11/29 03:08:01 jseger Exp $
#

DISTNAME=	sfio97
PKGNAME=	sfio-97
CATEGORIES=	devel
#Users must register with AT&T before downloading tarball.
#MASTER_SITES=	http://www.research.att.com/sw/tools/sfio/
EXTRACT_SUFX=	.src.unix.tar.Z

MAINTAINER=	jraynard@freebsd.org

NO_WRKSUBDIR=	yes
IS_INTERACTIVE=	yes
MAN3=		sfio.3 sfdisc.3

RESTRICTED=	Requires user to register with AT&T.

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	  ${ECHO} ""; \
	  ${ECHO} "Please read http://www.research.att.com/sw/tools/sfio/"; \
	  ${ECHO} "for details of how to obtain the SFIO source.  Put the"; \
	  ${ECHO} "file ${DISTNAME}${EXTRACT_SUFX} in the directory"; \
	  ${ECHO} "${DISTDIR} and run make again."; \
	  ${ECHO} ""; \
	  exit 1;\
	fi

# Remove a test that's too clever for its own good
# from the distribution, and a junk binary while we're at it.
post-extract:
	@${RM} ${WRKDIR}/src/lib/sfio/Sfio_t/tmmap2read.c
	@${RM} ${WRKDIR}/lib/libvdelta.a

do-build:
	@cd ${WRKDIR}/src/lib/sfio && ${MAKE} all -f makefile
	@cd ${WRKDIR}/src/lib/sfdisc && ${MAKE} all

do-install:
	${INSTALL_DATA} ${WRKDIR}/include/* ${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/lib/libsfdisc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/lib/libsfio.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/lib/libstdio.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKDIR}/man/man3/sfio.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKDIR}/man/man3/sfdisc.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
