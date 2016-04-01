# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mwlib.rl
PORTVERSION=	0.14.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate Pdfs from Mediawiki Markup

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/texvc:print/texvc \
		${LOCALBASE}/bin/fribidi:converters/fribidi \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}mwlib>=0.12.14:devel/py-mwlib \
		${PYTHON_PKGNAMEPREFIX}mwlib.ext>=0.12.3:devel/py-mwlib.ext \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:textproc/py-pygments
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
