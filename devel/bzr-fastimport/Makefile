# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	bzr-fastimport
PORTVERSION=	0.13.0
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/94774555/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Provide fast loading of revision control data into bzr

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr \
		${PYTHON_SITELIBDIR}/fastimport/__init__.py:${PORTSDIR}/devel/py-fastimport

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_fastimport
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.final.0

NO_STAGE=	yes
.include <bsd.port.mk>
