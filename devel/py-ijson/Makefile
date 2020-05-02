# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ijson
PORTVERSION=	3.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Iterative JSON parser with a standard Python iterator interface

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	YAJL
YAJL_DESC=	Enable yajl2_c backend

YAJL_LIB_DEPENDS=	libyajl.so:devel/yajl
YAJL_USES=		localbase:ldflags
YAJL_VARS_OFF=		NO_ARCH=yes

post-patch-YAJL-off:
	@${REINPLACE_CMD} -e 's|if embed_yajl or have_yajl|if False|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
