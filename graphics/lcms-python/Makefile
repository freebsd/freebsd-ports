# Created by: stas
# $FreeBSD$

PORTNAME=	lcms
PORTVERSION=	1.19
CATEGORIES=	graphics devel python
MASTER_SITES=	SF
PKGNAMESUFFIX=	-python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light Color Management System (python bindings)

LICENSE=	MIT

LIB_DEPENDS+=	lcms:${PORTSDIR}/graphics/lcms

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

USE_PYTHON=	2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-python
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_lcms.so \
		%%PYTHON_SITELIBDIR%%/lcms.py

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/.libs/_lcms.so \
		${PYTHON_SITELIBDIR}/_lcms.so
	${INSTALL_DATA} ${INSTALL_WRKSRC}/lcms.py \
		${PYTHON_SITELIBDIR}/lcms.py

.include <bsd.port.mk>
