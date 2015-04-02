# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	testoob
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced unit testing framework for PyUnit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/docs/LICENSE-2.0.txt

OPTIONS_DEFINE=	TWISTED
TWISTED_USES=	twisted
TWISTED_DESC=	enable running in threads

USES=		python tar:bzip2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
