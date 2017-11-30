# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	testoob
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	SF \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced unit testing framework for PyUnit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/docs/LICENSE-2.0.txt

OPTIONS_DEFINE=	TWISTED
TWISTED_DESC=	enable running in threads

NO_ARCH=	yes
USES=		python tar:bzip2
USE_PYTHON=	autoplist distutils

TWISTED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

.include <bsd.port.mk>
