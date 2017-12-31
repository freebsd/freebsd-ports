# Created by: blubee <hello@blubee.me>
# $FreeBSD$

PORTNAME=		pycangjie
PORTVERSION=		1.3
DISTVERSIONPREFIX=	v
CATEGORIES=		chinese

MAINTAINER=	hello@blubee.me
COMMENT=	Python wrapper to libcangjie

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS=	libcangjie.so:chinese/libcangjie

USES=		autoreconf gmake libtool pkgconfig sqlite python:3.2+
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Cangjians
GH_PROJECT=	pycangjie

post-install:
	(cd ${STAGEDIR}${PREFIX} \
  	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/*.py \
   	-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@(${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}/site-packages/cangjie/*.so)

.include <bsd.port.mk>
