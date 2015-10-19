# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ming
PORTVERSION=	0.4.7
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for Ming which allows you to create Flash 4/5 movies

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/../LICENSE_GPL2
LICENSE_FILE_LGPL21=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libming.so:${PORTSDIR}/graphics/ming \
		libpng.so:${PORTSDIR}/graphics/png

CONFIGURE_ARGS=	--enable-python
CONFIGURE_ENV=	PYTHON_LDFLAGS="-L${PYTHON_LIBDIR} -l${PYTHON_VERSION}${PYTHON_ABIVER}"
GNU_CONFIGURE=	yes
USE_PYTHON=	autoplist distutils
USES=		autoreconf libtool localbase python:2

CONFIGURE_WRKSRC=	${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME_EXTRACT}
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME_EXTRACT}/py_ext

USE_GITHUB=	yes
GH_ACCOUNT=	lib${PORTNAME}
GH_PROJECT=	lib${PORTNAME}
GH_TAGNAME=	${PORTNAME}-${PORTVERSION:S|.|_|g}

post-patch:
	@${REINPLACE_CMD} -e 's| --root ".*"||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/setup.py.in
	@${LN} -fs ${LOCALBASE}/include/ming ${WRKSRC}/../src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_mingc.so

.include <bsd.port.mk>
