# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pybench
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	benchmarks python
MASTER_SITES=	http://downloads.egenix.com/python/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible benchmark suite for Python

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		python shebangfix zip
SHEBANG_FILES=	platform.py
NO_ARCH=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/python -O|${python_CMD}|' \
		${WRKSRC}/pybench.py
	@${FIND} ${WRKSRC} -name \*.bak -delete

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PRINTF} '#!/bin/sh\n${PYTHON_CMD} ${DATADIR}/pybench.py "$$@"\n' \
		> ${WRKDIR}/pybench.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} --exclude README -C ${WRKSRC} -c -f - . \
		| ${TAR} --unlink -x -C ${STAGEDIR}${DATADIR} -f -
	${INSTALL_SCRIPT} ${WRKDIR}/pybench.sh ${STAGEDIR}${PREFIX}/bin/pybench

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
