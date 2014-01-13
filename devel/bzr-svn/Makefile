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

BUILD_DEPENDS+=	bzr:${PORTSDIR}/devel/bzr
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/subvertpy/__init__.py:${PORTSDIR}/devel/py-subvertpy \
		bzr:${PORTSDIR}/devel/bzr

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_svn

NO_STAGE=	yes
.include <bsd.port.mk>
