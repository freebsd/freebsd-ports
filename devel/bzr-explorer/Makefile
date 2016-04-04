# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	bzr-explorer
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/109861791/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop application for using bzr

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:devel/bzr
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bzrlib/plugins/qbzr/__init__.py:devel/qbzr \
		bzr:devel/bzr

USES=		gettext python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
