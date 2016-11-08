# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Elixir
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Declarative Mapper for SQLAlchemy

LICENSE=	MIT

DEPRECATED=	Depends on expired py-sqlalchemy06
EXPIRATION_DATE=	2016-12-08

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.4.0:databases/py-sqlalchemy06

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
