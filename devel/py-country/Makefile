# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	country
PORTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/p/pycountry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycountry-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python API for ISO country, subdivision, language and currency

USE_ZIP=	yes
USE_PYTHON=	yes
USES=		gettext:build
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	pycountry
PYTHON_PY3K_PLIST_HACK=	yes

NO_STAGE=	yes

post-patch:
	${RM} ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po.orig

pre-build:
	${LOCALBASE}/bin/msgfmt ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po -o ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.mo

.include <bsd.port.mk>
