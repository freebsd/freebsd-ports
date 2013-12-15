# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	anonfunc
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module that provides easy anonymous function

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
