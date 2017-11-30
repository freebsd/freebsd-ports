# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	pyface
PORTVERSION=	5.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Enthought traits-capable windowing framework

LICENSE=	BSD3CLAUSE LGPL21 EPL LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/image_LICENSE_Nuvola.txt
LICENSE_FILE_EPL=	${WRKSRC}/image_LICENSE_Eclipse.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/image_LICENSE_OOo.txt
#See file ${WRKSRC}/image_LICENSE.txt for files with non BSD3CLAUSE licenses

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=4.5.0:devel/py-traits@${FLAVOR}

USES=		python:-2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
