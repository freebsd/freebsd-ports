# Created by: Carlo Strub <c-s@c-s.li>
# $FreeBSD$

PORTNAME=	bzr-loom
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/94514373/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bazaar plugin to assist in developing focused patches

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:devel/bzr
RUN_DEPENDS=	bzr:devel/bzr

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
