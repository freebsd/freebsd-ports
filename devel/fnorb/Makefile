# New ports collection makefile for:	fnorb
# Date created:		12 Septermber 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fnorb
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	http://www.fnorb.org/download/ \
		ftp://ftp.dstc.edu.au/DSTC/fnorb/

MAINTAINER=	johann@egenetics.com

NO_CDROM=	Free for academic, research and non-commercial purposes only
WRKSRC=		${WRKDIR}/Fnorb-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_PYTHON=	yes
ALL_TARGET=

CPIO=		cpio --quiet -pdum -R
FNORB_DIR=	${PYTHON_SITELIBDIR}/Fnorb
FNORB_EGDIR=	${PREFIX}/share/examples/fnorb
FNORB_DOCDIR=	${PREFIX}/share/doc/fnorb
FNORB_BINS=	fnaming fnendian fnfeed fngen fnidl fnifr fnior fnlogger \
		fnmetrics fnmkior fnoptions fnping

do-configure:
	@ (cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  Makefile.pre.in boot)

post-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -f ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -f ${WRKSRC}

post-install:
	@ ${MKDIR} ${FNORB_DIR}/script
	@ (cd ${WRKSRC} && find *.py *.pyc *.pyo compiler cos orb parser \
	  script/*.py script/*.pyc script/*.pyo \! -name \*.orig \
	  | ${CPIO} ${BINOWN}:${BINGRP} ${FNORB_DIR})
	@ ${MKDIR} ${PREFIX}/bin
.for fnscript in ${FNORB_BINS}
	@ ${INSTALL_SCRIPT} ${WRKSRC}/script/${fnscript} ${PREFIX}/bin
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/etc/fnorb.cfg \
	  ${PREFIX}/etc/fnorb.cfg.sample
	@ ${MKDIR} ${FNORB_EGDIR}
	@ (cd ${WRKSRC}/examples && find * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${FNORB_EGDIR})
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${FNORB_DOCDIR}
	@ (cd ${WRKSRC}/doc && find . \
	  | ${CPIO} ${MANOWN}:${MANGRP} ${FNORB_DOCDIR})
	@ (${CHMOD} -R u-x ${FNORB_DOCDIR} && ${CHMOD} -R u+X ${FNORB_DOCDIR})
.for file in ANNOUNCE CHANGES README LICENSE.HTML
	@ ${INSTALL_MAN} ${WRKSRC}/${file} ${FNORB_DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
