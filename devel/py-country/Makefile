# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	country
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycountry-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python API for ISO country, subdivision, language and currency

USES=		gettext-tools:build python
USE_PYTHON=	distutils autoplist

post-patch:
	${RM} ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po.orig ${WRKSRC}/src/pycountry/locales/ru/LC_MESSAGES/iso639.po.orig ${WRKSRC}/src/pycountry/locales/uk/LC_MESSAGES/iso639.po.orig

pre-build:
	${LOCALBASE}/bin/msgfmt ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po -o ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.mo
	${LOCALBASE}/bin/msgfmt ${WRKSRC}/src/pycountry/locales/ru/LC_MESSAGES/iso639.po -o ${WRKSRC}/src/pycountry/locales/ru/LC_MESSAGES/iso639.mo
	${LOCALBASE}/bin/msgfmt ${WRKSRC}/src/pycountry/locales/uk/LC_MESSAGES/iso639.po -o ${WRKSRC}/src/pycountry/locales/uk/LC_MESSAGES/iso639.mo

.include <bsd.port.mk>
