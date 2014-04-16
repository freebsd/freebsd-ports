# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pg_activity
PORTVERSION=	1.0.2
CATEGORIES=	databases python
MASTER_SITES=	GH

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Top like utility for PostgreSQL activity monitoring

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:${PORTSDIR}/sysutils/py-psutil

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	julmon
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	ba36bae

USE_PYTHON=	yes
PYDISTUTILS_NOEGGINFO=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	${REINPLACE_CMD} -e 's|\/usr\/share|${MAN1PREFIX}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
