# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pg_activity
PORTVERSION=	1.2.0
CATEGORIES=	databases python
MASTER_SITES=	GH

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Top like utility for PostgreSQL activity monitoring

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:${PORTSDIR}/sysutils/py-psutil

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	julmon
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	3b6b371

USES=		python
USE_PYTHON=	distutils autoplist noegginfo
PYDISTUTILS_INSTALLARGS=	--with-man

post-patch:
	${REINPLACE_CMD} -e 's|\/usr\/share|${MAN1PREFIX}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
