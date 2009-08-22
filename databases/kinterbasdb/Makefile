# New ports collection makefile for:	kinterbasdb
# Date created:				19 November 2003
# Whom:					Dmytro Rud <rud@cs.uni-magdeburg.de>
#
# $FreeBSD$
#

PORTNAME=		kinterbasdb
PORTVERSION=		3.1.3
CATEGORIES=		databases python
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		${PORTNAME}-${PORTVERSION}.src

MAINTAINER=		rud@cs.uni-magdeburg.de
COMMENT=		Python extension for Firebird/Interbase(R) relational databases

LIB_DEPENDS=		gds.1:${PORTSDIR}/databases/firebird-client
RUN_DEPENDS=		${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py:${PORTSDIR}/lang/py-mx-base

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
USE_GCC=		3.4

PLIST_SUB=		INSTALLDIR=lib/${PYTHON_VERSION}/site-packages/${PORTNAME}

post-extract:
	@${REINPLACE_CMD} -e "s@DEFAULT_FREEBSD_HOME_DIR = '.*'@DEFAULT_FREEBSD_HOME_DIR = '${LOCALBASE}'@" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
