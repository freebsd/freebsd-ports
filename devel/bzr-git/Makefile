# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	bzr-git
PORTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/98666746/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for bzr to work with git trees

LICENSE=	GPLv2

BUILD_DEPENDS=	bzr:devel/bzr
RUN_DEPENDS=	bzr:devel/bzr \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.8.0:devel/dulwich \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
