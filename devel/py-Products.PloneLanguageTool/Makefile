PORTNAME=	Products.PloneLanguageTool
PORTVERSION=	3.2.7
PORTREVISION=	2
CATEGORIES=	devel python zope
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Allows to set the available languages in Plone site
WWW=		https://pypi.org/project/Products.PloneLanguageTool/

LICENSE=	GPLv2

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

post-patch:
	@${RM} ${WRKSRC}/Products/PloneLanguageTool/skins/LanguageTool/isTranslatable.py

.include <bsd.port.mk>
