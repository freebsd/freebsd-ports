# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	yappi
PORTVERSION=	0.82
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Yet Another Python Profiler

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	${RM} ${WRKSRC}/ez_setup.py
	${RM} ${WRKSRC}/distribute_setup.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
