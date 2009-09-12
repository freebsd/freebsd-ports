# New ports collection makefile for:	mwlib.rl
# Date created:		06 May, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mwlib.rl
PORTVERSION=	0.12.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Generate Pdfs from Mediawiki Markup

BUILD_DEPENDS=	${LOCALBASE}/bin/texvc:${PORTSDIR}/print/texvc \
		${LOCALBASE}/bin/fribidi:${PORTSDIR}/converters/fribidi \
		${PYTHON_PKGNAMEPREFIX}mwlib>=0.12.0:${PORTSDIR}/devel/py-mwlib \
		${PYTHON_PKGNAMEPREFIX}mwlib.ext>=0.12.0:${PORTSDIR}/devel/py-mwlib.ext \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.0:${PORTSDIR}/textproc/py-pygments
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GETTEXT=		yes
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
