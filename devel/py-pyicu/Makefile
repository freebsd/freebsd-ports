# Created by: bland@FreeBSD.org
# $FreeBSD$

PORTNAME=	pyicu
PORTVERSION=	1.9.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyICU-${PORTVERSION}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Python extension wrapping IBM's ICU C++ API #'

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES?=		python
USE_PYTHON=	distutils autoplist

MAKE_ENV+=	PYICU_INCLUDES="${PREFIX}/include" \
		PYICU_CFLAGS="-w:-DPYICU_VER=\"${PORTVERSION}\"" \
		PYICU_LFLAGS="-L${PREFIX}/lib"

LIB_DEPENDS+=	libicudata.so:devel/icu

pre-configure:
	@if [ ! -e ${LOCALBASE}/lib/libicule.so ]; then \
		${REINPLACE_CMD} "s/, 'icule'//" ${WRKSRC}/${PYSETUP}; \
	fi

.include <bsd.port.mk>
