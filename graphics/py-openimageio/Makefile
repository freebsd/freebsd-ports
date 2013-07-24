# Created by: Shane Ambler
# $FreeBSD$

PORTNAME=	openimageio
PORTREVISION=	1
CATEGORIES=	graphics multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	OpenImageIO python bindings

LICENSE=	BSD

LIB_DEPENDS=	OpenImageIO:${PORTSDIR}/graphics/openimageio \
		boost_python:${PORTSDIR}/devel/boost-python-libs

MASTERDIR=	${.CURDIR}/../openimageio

BROKEN=		Does not patch

USE_PYTHON=	2.6+

OIIO_PYBIND=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-CMakeLists.txt

do-install:
	${INSTALL_LIB} ${BUILD_WRKSRC}/python/OpenImageIO.so ${PYTHON_SITELIBDIR}/

.include "${MASTERDIR}/Makefile"
