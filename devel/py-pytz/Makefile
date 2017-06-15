# Created by: Khairil Yusof <kaeru@inigo-tech.com>
# $FreeBSD$

PORTNAME=	pytz
PORTVERSION=	2016.10
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	World Timezone Definitions for Python

LICENSE=	MIT

USES=		python tar:bzip2
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|=True|=False|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
