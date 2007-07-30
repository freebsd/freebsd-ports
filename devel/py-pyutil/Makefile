# New ports collection makefile for:	py-pyutil
# Date created:		2007-5-31
# Whom:			Chao Shin <quakelee@cn.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyutil
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/p/pyutil
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	quakelee@cn.FreeBSD.org
COMMENT=	A collection of mature utilities for Python programmers

USE_PYTHON=	2.4+
USE_PYDISTUTILS=easy_install
PYEASYINSTALL_ARCHDEP=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^from\ ez\_setup|#from\ ez\_setup|' \
	-e 's|^use_setuptools|#use_setuptools|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
