PORTNAME=	grizzled
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	The Grizzled Python Utility Library

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-patch:
	@${RM} ${WRKSRC}/ez_setup.py

.include <bsd.port.mk>
