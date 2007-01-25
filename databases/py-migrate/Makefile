# New ports collection makefile for:   py-migrate
# Date created:        9 November 2006
# Whom:                elvstone@gmail.com
#
# $FreeBSD$
#

PORTNAME=	migrate
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/m/migrate/ \
		http://dose.se/distfiles/migrate/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	elvstone@gmail.com
COMMENT=	Database schema migrations for SQLAlchemy

USE_PYTHON=	2.3+
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PYTHONVERSION=${_PYTHON_VERSION}
USE_PYDISTUTILS=	yes

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	${LOCALBASE}/share/examples/sqlalchemy/vertical/vertical.py:${PORTSDIR}/databases/py-sqlalchemy

.include <bsd.port.mk>
