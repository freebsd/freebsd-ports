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

LICENSE=	GPLv2

BUILD_DEPENDS+=	bzr:devel/bzr
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/subvertpy/__init__.py:devel/py-subvertpy \
		bzr:devel/bzr

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
