# New ports collection makefile for:	fnorb
# Date created:		12 Septermber 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fnorb
PORTVERSION=	1.1
PORTREVISION=	4
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
FNORB_SHAREDIR=	${PREFIX}/share/fnorb
FNORB_DOCDIR=	${PREFIX}/share/doc/fnorb

do-configure:
	@ (cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  Makefile.pre.in boot)

post-install:
	@ ${MKDIR} ${FNORB_DIR}
	@ (cd ${WRKSRC} && find *.py compiler cos orb parser \! -name \*.orig \
	  | ${CPIO} ${BINOWN}:${BINGRP} ${FNORB_DIR})
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -f ${FNORB_DIR}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -f ${FNORB_DIR}
	@ ${MKDIR} ${FNORB_SHAREDIR}
	@ (cd ${WRKSRC} && find script examples \! -name \*.bat \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${FNORB_SHAREDIR})
	@ ${INSTALL_DATA} ${WRKSRC}/etc/fnorb.cfg \
	  ${PREFIX}/etc/fnorb.cfg.sample
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
