# Created by: Carlo Strub <c-s@c-s.li>
# $FreeBSD$

PORTNAME=	bzr-builder
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/100761063/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	A bzr plugin to construct a bzr branch based on a "recipe"

LICENSE=	GPLv3

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_builder

NO_STAGE=	yes
.include <bsd.port.mk>
