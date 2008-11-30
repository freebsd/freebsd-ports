# New ports collection makefile for:	mwlib
# Date created:		27 June 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mwlib
PORTVERSION=	0.8.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python's MediaWiki Parser and Utility Library

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}odfpy>=0.7:${PORTSDIR}/devel/py-odfpy \
		${PYTHON_PKGNAMEPREFIX}simplejson>1.9:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}flup>=1.0:${PORTSDIR}/www/py-flup \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|install_requires=install_requires,||' \
		-e 's,checkpil()$$,,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
