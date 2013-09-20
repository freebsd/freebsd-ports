# Created by: Dryice Liu<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	Babel
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gaod@hychen.org
COMMENT=	Collection of tools for internationalizing Python applications

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USE_PYTHON=		2.7+
USE_PYDISTUTILS=	easy_install

PORTDOCS=	docs/*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${CP} -r ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
