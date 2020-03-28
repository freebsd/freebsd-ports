# $FreeBSD$

PORTNAME=	grammalecte-fr
PORTVERSION=	1.8.0
CATEGORIES=	french python
MASTER_SITES=	http://www.dicollecte.org/grammalecte/zip/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Grammalecte-fr-v${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	French grammar and typographic corrector

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:3.4+ zip
USE_PYTHON=	autoplist distutils

WRKSRC=		${WRKDIR}

.include <bsd.port.mk>
