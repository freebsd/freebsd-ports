# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	librtfcomp
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	archivers python
MASTER_SITES=	SF/synce/SynCE/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for library for handling compressed RTF documents

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyrex>0:devel/pyrex@${PY_FLAVOR}
LIB_DEPENDS=	librtfcomp.so:archivers/librtfcomp

CONFIGURE_ARGS=	--enable-python-bindings
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool python:2.7

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pyrtfcomp.a \
		%%PYTHON_SITELIBDIR%%/pyrtfcomp.so

post-patch:
	@${REINPLACE_CMD} -e '/VISIBILITY=/ s| -fvisibility=hidden||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[^ ]*/src/librtfcomp\.la||' ${WRKSRC}/python/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyrtfcomp.so

.include <bsd.port.mk>
