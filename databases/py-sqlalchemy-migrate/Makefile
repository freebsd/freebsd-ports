# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	sqlalchemy-migrate
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Database schema migrations for SQLAlchemy

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.7:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}Tempita>0:${PORTSDIR}/textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}decorator>0:${PORTSDIR}/devel/py-decorator

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
