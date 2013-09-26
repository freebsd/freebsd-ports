# Created by: Stanislav Svirid <count@211.ru>
# $FreeBSD$

PORTNAME=	south
PORTVERSION=	0.8.2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	South-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Intelligent schema migrations for Django apps

LICENSE=	AL2

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	South
PYTHON_PY3K_PLIST_HACK= yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
