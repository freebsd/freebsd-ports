# New ports collection makefile for:	py-exiv2
# Date created:		2008-06-01
# Whom:			Denis Barov <dindin@dindin.ru>
#
# $FreeBSD$
#

PORTNAME=	exiv2
PORTVERSION=	0.1.3
CATEGORIES=	graphics python
MASTER_SITES=	http://tilloy.net/dev/pyexiv2/releases/ \
		http://www.dindin.ru/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	dindin@dindin.ru
COMMENT=	Python bindings for exiv2

LIB_DEPENDS=	exiv2.7:${PORTSDIR}/graphics/exiv2\
		boost_python.4:${PORTSDIR}/devel/boost-python-libs

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_SCONS=	yes
USE_LDCONFIG=	yes
SCONS_ENV+=	PREFIX=${PREFIX} CPPPATH=${PREFIX}/inlude LIBPATH=${PREFIX}/lib
SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS+=	 prefix=${PREFIX} use_env=1

post-patch:
	${REINPLACE_CMD} -e 's|python_inc_path\]|python_inc_path,\
	"${PREFIX}/include"\]|' -e 's|LIBS=libs|LIBS=libs,\
	LIBPATH=\"${PREFIX}/lib\"|'\
	${WRKSRC}/src/SConscript

.include <bsd.port.mk>
