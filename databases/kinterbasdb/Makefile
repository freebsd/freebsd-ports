# New ports collection makefile for:	kinterbasdb
# Date created:				19 November 2003
# Whom:					Dmytro Rud <rud@cs.uni-magdeburg.de>
#
# $FreeBSD$
#

PORTNAME=		kinterbasdb
PORTVERSION=		3.1
VERSIONSUFFIX=		_pre6
CATEGORIES=		python databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kinterbasdb
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		${PORTNAME}-${PORTVERSION}${VERSIONSUFFIX}-src

MAINTAINER=		rud@cs.uni-magdeburg.de
COMMENT=		Python extension for Firebird/Interbase(R) relational databases

LIB_DEPENDS=		gds.1:${PORTSDIR}/databases/firebird
RUN_DEPENDS=		${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py:${PORTSDIR}/lang/py-mx-base

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}${VERSIONSUFFIX}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

PLIST_SUB=		INSTALLDIR=lib/${PYTHON_VERSION}/site-packages/${PORTNAME}

.include <bsd.port.mk>
