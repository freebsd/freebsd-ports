# $FreeBSD$

PORTNAME=	hgreviewboard
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://bitbucket.org/ccaughie/hgreviewboard/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	hgreviewboard

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Mercurial reviewboard extension

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	hg:devel/mercurial \
		rbt:devel/rbtools

WRKSRC=		${WRKDIR}/ccaughie-hgreviewboard-e461a0baf62d
USES=		python

NO_BUILD=	yes

post-patch:
	${SED} -i '' -e 's/import simplejson/import json as simplejson/' \
		${WRKSRC}/reviewboard.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/reviewboard
	${INSTALL_DATA} ${WRKSRC}/__init__.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/reviewboard
	${INSTALL_DATA} ${WRKSRC}/reviewboard.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/reviewboard

.include <bsd.port.mk>
