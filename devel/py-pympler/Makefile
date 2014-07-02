# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pympler
PORTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Measure, monitor and analyze the memory behavior of Python objects

LICENSE=	APACHE20

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%STAGEDIR%%,${STAGEDIR},g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
