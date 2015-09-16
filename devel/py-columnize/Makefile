# $FreeBSD$

PORTNAME=	columnize
PORTVERSION=	0.3.8
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Format a simple (i.e. not nested) list into aligned columns

LICENSE=	MIT

MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:${PORTSDIR}/devel/py-nose
MY_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.shutil_get_terminal_size=1.0:${PORTSDIR}/devel/py-backports.shutil_get_terminal_size

BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
