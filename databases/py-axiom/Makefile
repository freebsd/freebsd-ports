# New ports collection makefile for:	py-axiom
# Date created:				13 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	axiom
PORTVERSION=	0.4.0
CATEGORIES=	databases python
MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Axiom-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz?format=raw

MAINTAINER=	alex@foxybanana.com
COMMENT=	Axiom is an object database in python using sqlite3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/epsilon/__init__.py:${PORTSDIR}/devel/py-epsilon
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/epsilon/__init__.py:${PORTSDIR}/devel/py-epsilon \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite21

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
