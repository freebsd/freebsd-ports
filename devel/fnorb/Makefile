# New ports collection makefile for:	fnorb
# Date created:		12 Septermber 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	fnorb
PORTVERSION=	1.1
PORTREVISION=	9
CATEGORIES=	devel python
MASTER_SITES=	http://www.fnorb.org/download/

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=		${WRKDIR}/Fnorb-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
USE_PYTHON=	yes
ALL_TARGET=

CPIO=		cpio --quiet -pdum -R
FNORB_DIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages/Fnorb
FNORB_BINS=	fnaming fnendian fnfeed fngen fnidl fnifr fnior fnlogger \
		fnmetrics fnmkior fnoptions fnping

do-configure:
	@ cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	  Makefile.pre.in boot

post-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -f ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -f ${WRKSRC}

post-install:
	@ ${MKDIR} ${FNORB_DIR}/script
	@ cd ${WRKSRC} && find *.py *.pyc *.pyo compiler cos orb parser \
	  script/*.py script/*.pyc script/*.pyo \! -name \*.orig \
	  | ${CPIO} ${BINOWN}:${BINGRP} ${FNORB_DIR}
	@ ${MKDIR} ${PREFIX}/bin
.for fnscript in ${FNORB_BINS}
	@ ${INSTALL_SCRIPT} ${WRKSRC}/script/${fnscript} ${PREFIX}/bin
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/etc/fnorb.cfg \
	  ${PREFIX}/etc/fnorb.cfg.sample
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${EXAMPLESDIR}
	@ cd ${WRKSRC}/examples && find * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC}/doc && find . \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ ${CHMOD} -R u-x ${DOCSDIR} && ${CHMOD} -R u+X ${DOCSDIR}
.for file in ANNOUNCE CHANGES README LICENSE.HTML
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
