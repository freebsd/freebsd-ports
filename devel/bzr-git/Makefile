# Ports collection makefile for:	bzr-git
# Date created:		9 August 2010
# Whom:			Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-git
PORTVERSION=	0.6.7
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/90978988/ \
		http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Plugin for bzr to work with git trees

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng \
		py*-dulwich>=0.8.0:${PORTSDIR}/devel/dulwich \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_git

.include <bsd.port.mk>
