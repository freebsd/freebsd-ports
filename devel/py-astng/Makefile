# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	astng
PORTVERSION=	0.24.3
CATEGORIES=	devel python
MASTER_SITES=	LOGILAB
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	logilab-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Extension for Python compiler.ast module

LICENSE=	LGPL21

RUN_DEPENDS=	pytest:${PORTSDIR}/devel/py-logilab-common

MAKE_ENV=		NO_SETUPTOOLS=1
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	logilab-astng

.include <bsd.port.pre.mk>

post-patch:
	@${CHMOD} a+r ${WRKSRC}/brain/*.py

.include <bsd.port.post.mk>
