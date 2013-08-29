# Created by: Carlo Strub <c-s@c-s.li>
# $FreeBSD$

PORTNAME=	bzr-grep
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/49936719/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Bazaar plugin to grep files

BROKEN=		conflicts with dependency bzr

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bzr

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_grep
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.final.0

.include <bsd.port.mk>
