# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	setproctitle
PORTVERSION=	1.1.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python module to customize the process title

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		python
USE_PYTHON=	autoplist distutils

PORTDOCS=	COPYRIGHT HISTORY.rst README.rst

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/setproctitle.so

do-test:
	@cd ${WRKSRC}/tests && ${PYTHON_CMD} ${WRKSRC}/tests/setproctitle_test.py

.include <bsd.port.mk>
