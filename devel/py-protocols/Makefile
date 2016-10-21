# Created by: Nicola Vitale
# $FreeBSD$

PORTNAME=	protocols
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://peak.telecommunity.com/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyProtocols-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module extending the PEP 246 adapt() function

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${RM} -r ${WRKSRC}/setuptools

.include <bsd.port.mk>
