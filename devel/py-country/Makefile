# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	country
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycountry-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python API for ISO country, subdivision, language and currency

USES=		gettext-tools:build python zip
USE_PYTHON=	distutils autoplist

post-patch:
	${RM} ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po.orig

pre-build:
	${LOCALBASE}/bin/msgfmt ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po -o ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.mo

.include <bsd.port.mk>
