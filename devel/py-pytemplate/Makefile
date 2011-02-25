# New ports collection makefile for:   pytemplate
# Date created:		2009-02-24
# Whom:			Benoit Calvez <benoit@litchis.org>
#
# $FreeBSD$

PORTNAME=	pytemplate
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.bulot.org/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	benoit@litchis.org
COMMENT=	Pytemplate gives python developpers a starting framework

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-pytemplate

EXAMPLES=	daemonexample.py example.py threadexample.py

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
