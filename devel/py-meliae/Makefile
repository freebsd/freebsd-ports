# $FreeBSD$

PORTNAME=	meliae
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://launchpadlibrarian.net/74803944/ \
		LOCAL/${MAINTAINER:C/([^@]*)@.*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python Memory Usage Analyzer

LICENSE=	GPLv3

BUILD_DEPENDS=	cython>0:${PORTSDIR}/lang/cython

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: extract
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
