# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	bzr-externals
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/91495699/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support external branches like svn:externals

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:devel/bzr
RUN_DEPENDS=	bzr:devel/bzr

WRKSRC=		${WRKDIR}/externals

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
