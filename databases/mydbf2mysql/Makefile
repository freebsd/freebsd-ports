# Created by: Andrey Polyakov <andrey.polyakov@unix.net>
# $FreeBSD$

PORTNAME=	mydbf2mysql
PORTVERSION=	0.8.4.5
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	SF/mydbf2mysql/mydbf2mysql/${PORTVERSION}/
DISTNAME=	MyDBF2MySQL-${PORTVERSION}

MAINTAINER=	andrey.polyakov@unix.net
COMMENT=	Flexible tool for DBF import into MySQL

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
RUN_DEPENDS+=	ydbf=0.0.1:${PORTSDIR}/devel/py-ydbf

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=yes
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}/dist/${DISTNAME}/

.include <bsd.port.mk>
