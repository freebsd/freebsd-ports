# New ports collection makefile for:   mydbf2mysql
# Date created:        10 Jan 2010
# Whom:                Andrey Polyakov <andrey.polyakov@unix.net>
#
# $FreeBSD$
#

PORTNAME=	mydbf2mysql
PORTVERSION=	0.8.4.5
CATEGORIES=	databases python
MASTER_SITES=	SF/mydbf2mysql/mydbf2mysql/${PORTVERSION}/
DISTNAME=	MyDBF2MySQL-${PORTVERSION}

MAINTAINER=	andrey.polyakov@unix.net
COMMENT=	Flexible tool for DBF import into MySQL

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
RUN_DEPENDS+=	ydbf=0.0.1:${PORTSDIR}/devel/py-ydbf

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}
USE_PYTHON=	2.6+
USE_PYDISTUTILS=yes
USE_BZIP2=	yes
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGNAME=	MyDBF2MySQL
PYDISTUTILS_PKGVERSION=	${PORTVERSION}

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}/dist/${DISTNAME}/

MAN1=	mydbf2mysql.1

.include <bsd.port.mk>
