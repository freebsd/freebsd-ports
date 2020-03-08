# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	pyst
PORTVERSION=	0.6.50
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/pyst/${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Python interface to allow Asterisk programming

LICENSE=	LGPL21 PSFL
LICENSE_COMB=	dual

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7
USE_PYTHON=	distutils
NO_ARCH=	yes

PORTDOCS=	README README.html ChangeLog

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
