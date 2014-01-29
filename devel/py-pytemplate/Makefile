# Created by: Benoit Calvez <benoit@litchis.org>
# $FreeBSD$

PORTNAME=	pytemplate
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://www.bulot.org/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	benoit@litchis.org
COMMENT=	Pytemplate gives python developers a starting framework

LICENSE=	GPLv3

USE_PYTHON=	2
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-pytemplate

EXAMPLES=	daemonexample.py example.py threadexample.py

NO_STAGE=	yes
post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
