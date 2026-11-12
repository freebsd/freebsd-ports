PORTNAME=	wkb-wkt-converter
PORTVERSION=	0.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	wkb_wkt_converter-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High-performance streaming converter between WKT and WKB geometry formats
WWW=		https://github.com/adrien-berchet/WKB_WKT_Converter

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.0<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
WRKSRC=		${WRKDIR}/wkb_wkt_converter-${PORTVERSION}

.include <bsd.port.mk>
