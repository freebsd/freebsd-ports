# Ports collection makefile for:	py-htsql
# Date created:			Dec 17, 2010
# Whom:				jpaetzel
#
# $FreeBSD$
#

PORTNAME=	htsql
PORTVERSION=	2.3.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python HTSQL

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:U}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
