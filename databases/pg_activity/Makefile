# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pg_activity
PORTVERSION=	1.0.1
CATEGORIES=	databases python
MASTER_SITES=	GH

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Top like utility for PostgreSQL activity monitoring

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:${PORTSDIR}/sysutils/py-psutil

USE_GITHUB=	yes
GH_ACCOUNT=	julmon
GH_TAGNAME=	v1.0.1
GH_COMMIT=	c002fc9

USE_PYTHON=	yes
PYDISTUTILS_NOEGGINFO=	yes
USE_PYDISTUTILS=	easy_install

MAN1=	pg_activity.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/man/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
