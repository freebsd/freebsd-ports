# New ports collection makefile for:    pybench
# Date created:         		29 March 2001
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pybench
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	benchmarks python
MASTER_SITES=	http://www.lemburg.com/files/python/

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_PYTHON=	yes

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/pybench
	@(cd ${WRKSRC} && ${TAR} --exclude README -c -f - .) \
		| (cd ${PREFIX}/share/pybench && ${TAR} --unlink -x -f -)
	@printf '#!/bin/sh\n${PYTHON_CMD} ${PREFIX}/share/pybench/pybench.py "$$@"\n' \
		> ${WRKDIR}/pybench.sh
	@${MKDIR} ${PREFIX}/share/doc/pybench
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/pybench
	@${INSTALL_SCRIPT} ${WRKDIR}/pybench.sh ${PREFIX}/bin/pybench

.include <bsd.port.mk>
