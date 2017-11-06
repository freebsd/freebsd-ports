# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	exiv2
PORTVERSION=	0.3.2
PORTREVISION=	9
CATEGORIES=	graphics python
MASTER_SITES=	https://launchpadlibrarian.net/83595798/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Python bindings for exiv2

LIB_DEPENDS=	libexiv2.so:graphics/exiv2\
		libboost_python.so:devel/boost-python-libs

USES=		python:2 scons tar:bzip2
USE_LDCONFIG=	yes
CXXFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS+=	prefix=${PREFIX} use_env=1

post-patch:
	${REINPLACE_CMD} -e 's|python_inc_path\]|python_inc_path,\
	"${PREFIX}/include"\]|' -e 's|LIBS=libs|LIBS=libs,\
	LIBPATH=\"${PREFIX}/lib\"|'\
	${WRKSRC}/src/SConscript

post-install:
	cd ${STAGEDIR}/${PYTHON_SITELIBDIR}/pyexiv2; ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py .

regression-test: build
	@cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
