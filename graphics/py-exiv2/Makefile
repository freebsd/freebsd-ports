# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	exiv2
PORTVERSION=	0.3.2
CATEGORIES=	graphics python
MASTER_SITES=	https://launchpadlibrarian.net/83595798/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Python bindings for exiv2

LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2\
		boost_python:${PORTSDIR}/devel/boost-python-libs

USE_PYTHON=	-2.7
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_SCONS=	yes
USE_LDCONFIG=	yes
SCONS_ENV+=	PREFIX=${PREFIX} CPPPATH=${PREFIX}/include LIBPATH=${PREFIX}/lib
SCONS_BUILDENV=	${SCONS_ENV} CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
SCONS_ARGS+=	prefix=${PREFIX} use_env=1

post-patch:
	${REINPLACE_CMD} -e 's|python_inc_path\]|python_inc_path,\
	"${PREFIX}/include"\]|' -e 's|LIBS=libs|LIBS=libs,\
	LIBPATH=\"${PREFIX}/lib\"|'\
	${WRKSRC}/src/SConscript

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PYTHON_SITELIBDIR}/pyexiv2

regression-test: build
	@cd ${WRKSRC} && ${SCONS_BIN} test

.include <bsd.port.mk>
