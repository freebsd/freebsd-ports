# New ports collection makefile for:	openark-kit
# Date created:		2009-02-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	openark-kit
PORTVERSION=	111
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gslin@gslin.org
COMMENT=	Common utilities for MySQL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb

PROJECTHOST=	openarkkit
USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

LICENSE=	BSD

.include <bsd.port.mk>
