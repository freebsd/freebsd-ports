# Created by: Carlo Strub (c-s@c-s.li)
# $FreeBSD$

PORTNAME=	subvertpy
PORTVERSION=	0.9.2
CATEGORIES=	devel
MASTER_SITES=	https://jelmer.uk/subvertpy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python bindings for subversion

LICENSE=	GPLv2

BUILD_DEPENDS+=	svn:devel/subversion

USES=		python:2.7
USE_PYTHON=	distutils autoplist
MAKE_ENV=	HOME=/dev/null
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
