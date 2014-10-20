# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	pyst
PORTVERSION=	0.6.50
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/pyst/${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Python interface to allow Asterisk programming

LICENSE=	LGPL21 PSFL
LICENSE_COMB=	dual

USES=		python:2
USE_PYTHON=	distutils

PORTDOCS=	README README.html ChangeLog

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
