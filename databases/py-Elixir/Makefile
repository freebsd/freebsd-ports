# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Elixir
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Declarative Mapper for SQLAlchemy

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.4.0:${PORTSDIR}/databases/py-sqlalchemy06

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
