# Created by: Benoit Calvez <benoit@litchis.org>
# $FreeBSD$

PORTNAME=	pytemplate
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://www.bulot.org/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	benoit@litchis.org
COMMENT=	Pytemplate gives python developers a starting framework

LICENSE=	GPLv3

USES=		python:2.7
USE_PYTHON=	distutils

EXAMPLESDIR=	${PREFIX}/share/examples/py-pytemplate

EXAMPLES=	daemonexample.py example.py threadexample.py

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
