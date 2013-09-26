# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	mccabe
PORTVERSION=	0.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Ned\'s script to check McCabe complexity

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYTHON_PY3K_PLIST_HACK=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
