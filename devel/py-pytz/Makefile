# Created by: Khairil Yusof <kaeru@inigo-tech.com>
# $FreeBSD$

PORTNAME=	pytz
PORTVERSION=	2014.1.1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	World Timezone Definitions for Python

LICENSE=	MIT

USES=	tar:bzip2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|=True|=False|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
