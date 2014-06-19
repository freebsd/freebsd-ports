# Created by: Wen Heping <wenheping@wenheping.com>
# $FreeBSD$

PORTNAME=	pisa
PORTVERSION=	3.0.33
PORTREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PDF generator using HTML and CSS

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.11.1:${PORTSDIR}/www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}reportlab2>=2.1:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}imaging>=0.1:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pdf>=1.12:${PORTSDIR}/print/py-pdf

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
