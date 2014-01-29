# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htsql-mysql
PORTVERSION=	2.3.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Database Query Language (MySQL Backend for HTSQL)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}htsql>2.3:${PORTSDIR}/databases/py-htsql \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>0:${PORTSDIR}/databases/py-MySQLdb

USE_PYTHON=		2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:U}

NO_STAGE=	yes
.include <bsd.port.mk>
