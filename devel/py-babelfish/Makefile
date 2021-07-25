# Created by: William Grzybowski <wg@FreeBSD.org>

PORTNAME=	babelfish
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/Diaoul/${PORTNAME}/commit/
PATCHFILES+=	7667fb3179e4.patch:-p1 # https://github.com/Diaoul/babelfish/pull/29

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Module to work with countries and languages

LICENSE=	BSD3CLAUSE

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
