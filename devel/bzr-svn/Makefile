# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	bzr-svn
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/102178824/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for bzr to work with svn

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2

BUILD_DEPENDS+=	bzr:devel/bzr
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/subvertpy/__init__.py:devel/py-subvertpy@${PY_FLAVOR} \
		bzr:devel/bzr

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
