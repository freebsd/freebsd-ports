# $FreeBSD$

PORTNAME=	tld
PORTVERSION=	0.7.10
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Extract the top level domain (TLD) from the URL given

LICENSE=	MPL11 GPLv2 LGPL21
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR}

NO_ARCH=	yes
USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	src/tld/bin/update-tld-names

.include <bsd.port.mk>
