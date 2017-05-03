# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ruamel.yaml
PORTVERSION=	0.14.5
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	YAML 1.2 loader/dumper package for Python

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	@${RM} ${WRKSRC}/LICENSE

.include <bsd.port.mk>
