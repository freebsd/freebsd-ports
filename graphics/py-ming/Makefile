# Created by: Akinori MUSHA aka knu <knu@idaemons.org>

PORTNAME=	ming
DISTVERSIONPREFIX=	ming-
DISTVERSION=	0_4_8
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for Ming which allows you to create Flash 4/5 movies

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE_GPL2
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libming.so:graphics/ming \
		libpng.so:graphics/png

USES=		autoreconf libtool localbase:ldflags python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFIGURE_ARGS=	--enable-python
CONFIGURE_ENV=	PYTHON_LDFLAGS="-L${PYTHON_LIBDIR} -l${PYTHON_VERSION}${PYTHON_ABIVER}"
GNU_CONFIGURE=	yes

BUILD_WRKSRC=	${WRKSRC}/py_ext
INSTALL_WRKSRC=	${WRKSRC}/py_ext

USE_GITHUB=	yes
GH_ACCOUNT=	libming
GH_PROJECT=	libming

PORTSCOUT=	limit:^ming-

post-patch:
	@${REINPLACE_CMD} -e 's| --root ".*"||' ${WRKSRC}/py_ext/Makefile.am
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/py_ext/setup.py.in
	@${LN} -fs ${LOCALBASE}/include/ming ${WRKSRC}/src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_mingc*.so

.include <bsd.port.mk>
