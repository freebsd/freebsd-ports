# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	bzr-explorer
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/109861791/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Desktop application for using bzr

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bzrlib/plugins/qbzr/__init__.py:${PORTSDIR}/devel/qbzr \
		bzr:${PORTSDIR}/devel/bzr

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	explorer
USES=		gettext

NO_STAGE=	yes
.include <bsd.port.mk>
