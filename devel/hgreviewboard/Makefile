PORTNAME=	hgreviewboard
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	https://bitbucket.org/ccaughie/hgreviewboard/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	hgreviewboard

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mercurial reviewboard extension

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PY_MERCURIAL} \
		rbt:devel/rbtools

WRKSRC=		${WRKDIR}/ccaughie-hgreviewboard-e461a0baf62d
USES=		python

NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/import simplejson/import json as simplejson/' \
		${WRKSRC}/reviewboard.py

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/reviewboard
	${INSTALL_DATA} ${WRKSRC}/__init__.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/reviewboard
	${INSTALL_DATA} ${WRKSRC}/reviewboard.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/reviewboard

.include <bsd.port.mk>
