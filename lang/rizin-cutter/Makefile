PORTNAME=	cutter
PORTVERSION=	2.4.1
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	lang devel
PKGNAMEPREFIX=	rizin-

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Free and Open Source Reverse Engineering Platform
WWW=		https://cutter.re/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyaml>=23.5.9:textproc/py-pyaml@${PY_FLAVOR}
LIB_DEPENDS=	librz_core.so:lang/rizin \
		libgvc.so:graphics/graphviz

USES=		cmake desktop-file-utils pkgconfig python:env qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	rizinorg
GH_TUPLE=	rizinorg:cutter-translations:8d5d2f9b3:translations/src/translations

USE_QT=		5compat base svg tools

CMAKE_ARGS=	-DCUTTER_USE_BUNDLED_RIZIN=OFF -DCUTTER_QT6=ON

.include <bsd.port.mk>
