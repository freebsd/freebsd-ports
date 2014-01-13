# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mwlib.rl
PORTVERSION=	0.14.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generate Pdfs from Mediawiki Markup

BUILD_DEPENDS=	${LOCALBASE}/bin/texvc:${PORTSDIR}/print/texvc \
		${LOCALBASE}/bin/fribidi:${PORTSDIR}/converters/fribidi \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}mwlib>=0.12.14:${PORTSDIR}/devel/py-mwlib \
		${PYTHON_PKGNAMEPREFIX}mwlib.ext>=0.12.3:${PORTSDIR}/devel/py-mwlib.ext \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:${PORTSDIR}/textproc/py-pygments
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_ZIP=	yes
USES=		gettext
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
