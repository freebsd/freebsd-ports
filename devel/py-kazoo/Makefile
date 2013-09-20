# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kazoo
PORTVERSION=	0.8
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Python library that makes it easier to use Zookeeper

LICENSE=	AL2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}gevent>=0.13.8:${PORTSDIR}/devel/py-gevent
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	python-zk
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	439afe5

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGVERSION=	${PORTVERSION}dev

USE_GMAKE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
