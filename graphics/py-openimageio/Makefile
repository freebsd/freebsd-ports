# Created by: Shane Ambler
# $FreeBSD$

PORTNAME=	openimageio
CATEGORIES=	graphics multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	OpenImageIO python bindings

LICENSE=	BSD

LIB_DEPENDS=	OpenImageIO:${PORTSDIR}/graphics/openimageio \
		boost_python:${PORTSDIR}/devel/boost-python-libs

MASTERDIR=	${.CURDIR}/../openimageio

USE_PYTHON=	2.6+

OIIO_PYBIND=	yes

do-install:
	${INSTALL_LIB} ${BUILD_WRKSRC}/python/OpenImageIO.so ${PYTHON_SITELIBDIR}/

.include "${MASTERDIR}/Makefile"
