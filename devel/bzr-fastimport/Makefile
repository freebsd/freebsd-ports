# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	bzr-fastimport
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}+bzr361
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide fast loading of revision control data into bzr

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:devel/bzr
RUN_DEPENDS=	bzr:devel/bzr \
		${PYTHON_SITELIBDIR}/fastimport/__init__.py:devel/py-fastimport@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
PATCH_STRIP=	-p1

.include <bsd.port.mk>
