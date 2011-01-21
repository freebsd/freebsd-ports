# New ports collection makefile for:   py-migrate
# Date created:        9 November 2006
# Whom:                elvstone@gmail.com
#
# $FreeBSD$
#

PORTNAME=	migrate
PORTVERSION=	0.6
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://dose.se/distfiles/migrate/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sqlalchemy-${PORTNAME}-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Database schema migrations for SQLAlchemy

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}Tempita>0:${PORTSDIR}/textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}decorator>0:${PORTSDIR}/devel/py-decorator

PROJECTHOST=	sqlalchemy-migrate
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	sqlalchemy_${PORTNAME}

LICENSE=	MIT

.include <bsd.port.mk>
