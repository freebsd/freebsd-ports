# $FreeBSD$

PORTNAME=	astroid
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	https://bitbucket.org/logilab/astroid/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-version-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Extension for Python compiler.ast module

LICENSE=	LGPL21

RUN_DEPENDS=	pytest:${PORTSDIR}/devel/py-logilab-common

WRKSRC=			${WRKDIR}/logilab-astroid-1d6914a1a1a0
MAKE_ENV=		NO_SETUPTOOLS=1
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	astroid

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${CHMOD} a+r ${WRKSRC}/brain/*.py

.include <bsd.port.post.mk>
