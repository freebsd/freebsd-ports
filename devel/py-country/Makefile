# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	country
PORTVERSION=	1.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/p/pycountry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycountry-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python API for ISO country, subdivision, language and currency

USES=		zip gettext:build
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	${RM} ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po.orig

pre-build:
	${LOCALBASE}/bin/msgfmt ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.po -o ${WRKSRC}/src/pycountry/locales/tr/LC_MESSAGES/iso639.mo

.include <bsd.port.mk>
