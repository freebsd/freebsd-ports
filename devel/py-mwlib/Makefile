# New ports collection makefile for:	mwlib
# Date created:		27 June 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mwlib
PORTVERSION=	0.11.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python's MediaWiki Parser and Utility Library

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyparsing.py:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}odfpy>=0.8:${PORTSDIR}/devel/py-odfpy \
		${PYTHON_PKGNAMEPREFIX}simplejson>2.0.8:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}flup>=1.0:${PORTSDIR}/www/py-flup \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.4.1:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}twisted>=8.2.0:${PORTSDIR}/devel/py-twisted

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|odfpy==0.7.0|odfpy>=0.7.0|' \
		-e 's|, "twisted>=8.2"||' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
