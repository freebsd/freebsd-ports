# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pybench
PORTVERSION=	2.0
CATEGORIES=	benchmarks python
MASTER_SITES=	http://downloads.egenix.com/python/
EXTRACT_SUFX=	.zip

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	An extensible benchmark suite for Python

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes

PORTDOCS=	README

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} --exclude README -C ${WRKSRC} -c -f - . \
		| ${TAR} --unlink -x -C ${STAGEDIR}${DATADIR} -f -
	@${PRINTF} '#!/bin/sh\n${PYTHON_CMD} ${DATADIR}/pybench.py "$$@"\n' \
		> ${WRKDIR}/pybench.sh
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/pybench.sh ${STAGEDIR}${PREFIX}/bin/pybench

.include <bsd.port.mk>
