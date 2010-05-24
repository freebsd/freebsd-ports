# New ports collection makefile for:	py-pyke
# Date created:		2008-12-23
# Whom:			Thinker K.F. Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	pyke
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Knowledge Engine

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=2.3:${PORTSDIR}/devel/py-ply

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
