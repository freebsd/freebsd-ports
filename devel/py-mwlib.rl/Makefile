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

BUILD_DEPENDS=	${LOCALBASE}/bin/texvc:${PORTSDIR}/print/texvc \
		${LOCALBASE}/bin/fribidi:${PORTSDIR}/converters/fribidi \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}mwlib>=0.12.14:${PORTSDIR}/devel/py-mwlib \
		${PYTHON_PKGNAMEPREFIX}mwlib.ext>=0.12.3:${PORTSDIR}/devel/py-mwlib.ext \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:${PORTSDIR}/textproc/py-pygments
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=			zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
