# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mwlib
PORTVERSION=	0.15.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python's MediaWiki Parser and Utility Library

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parsing>0:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}odfpy>=0.9:${PORTSDIR}/devel/py-odfpy \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.8:${PORTSDIR}/devel/py-lockfile \
		${PYTHON_PKGNAMEPREFIX}timelib>=0.2:${PORTSDIR}/devel/py-timelib \
		${PYTHON_PKGNAMEPREFIX}pdf>=1.12:${PORTSDIR}/print/py-pdf \
		${PYTHON_PKGNAMEPREFIX}simplejson>2.0.8:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}flup>=1.0:${PORTSDIR}/www/py-flup \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pylib>=1.4.0:${PORTSDIR}/devel/py-pylib \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}apipkg>=0:${PORTSDIR}/devel/py-apipkg \
		${PYTHON_PKGNAMEPREFIX}qserve>=0:${PORTSDIR}/devel/py-qserve \
		${PYTHON_PKGNAMEPREFIX}roman>=0:${PORTSDIR}/math/py-roman \
		${PYTHON_PKGNAMEPREFIX}sqlite3dbm>=0:${PORTSDIR}/databases/py-sqlite3dbm

USE_ZIP=		yes
USE_PYTHON=		2
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} \
		-e 's|lockfile==|lockfile>=|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
