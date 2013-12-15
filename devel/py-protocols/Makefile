# Created by: Nicola Vitale
# $FreeBSD$

PORTNAME=	protocols
PORTVERSION=	0.9.3
CATEGORIES=	devel python
MASTER_SITES=	http://peak.telecommunity.com/dist/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyProtocols-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module extending the PEP 246 adapt() function

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyProtocols

NO_STAGE=	yes

post-patch:
	@${RM} -rf ${WRKSRC}/setuptools

.include <bsd.port.mk>
