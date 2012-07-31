# New ports collection makefile for:	py-exiv2
# Date created:		2008-06-01
# Whom:			Denis Barov <dindin@dindin.ru>
#
# $FreeBSD$
#

PORTNAME=	exiv2
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://launchpadlibrarian.net/61465005/ \
		http://www.dindin.ru/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Python bindings for exiv2

LIB_DEPENDS=	exiv2.12:${PORTSDIR}/graphics/exiv2\
		boost_python.4:${PORTSDIR}/devel/boost-python-libs

USE_PYTHON=	yes
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

.include <bsd.port.mk>
