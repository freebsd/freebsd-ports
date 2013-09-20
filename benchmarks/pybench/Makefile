# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pybench
PORTVERSION=	2.0
CATEGORIES=	benchmarks python
MASTER_SITES=	http://downloads.egenix.com/python/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	An extensible benchmark suite for Python

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_PYTHON=	yes

PORTDOCS=	README

NO_STAGE=	yes
do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${TAR} --exclude README -c -f - .) \
		| (cd ${DATADIR} && ${TAR} --unlink -x -f -)
	@${PRINTF} '#!/bin/sh\n${PYTHON_CMD} ${DATADIR}/pybench.py "$$@"\n' \
		> ${WRKDIR}/pybench.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_SCRIPT} ${WRKDIR}/pybench.sh ${PREFIX}/bin/pybench

.include <bsd.port.mk>
