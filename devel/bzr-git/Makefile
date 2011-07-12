# Ports collection makefile for:	bzr-git
# Date created:		9 August 2010
# Whom:			Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	bzr-git
PORTVERSION=	0.6.1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/73756120/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Plugin for bzr to work with git trees

BUILD_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng
RUN_DEPENDS=	bzr:${PORTSDIR}/devel/bazaar-ng \
		${PYTHON_SITELIBDIR}/dulwich/__init__.py:${PORTSDIR}/devel/dulwich \
		py*-pysqlite>=2.3:${PORTSDIR}/databases/py-pysqlite23

LICENSE=	GPLv2

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr_git

.include <bsd.port.mk>
