# $FreeBSD$

PORTNAME=	kajongg
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	7
CATEGORIES=	games kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cmake:outsource kde:4 python:2.7 tar:xz shebangfix sqlite
USE_KDE=	kdelibs pykde4 automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DINSTALL_KAJONGG:BOOL=TRUE

SHEBANG_FILES=	src/kajongg.py \
		src/kajonggserver.py \
		src/kajonggtest.py

.include <${.CURDIR}/../kdegames-kde4/Makefile.common>
.include <bsd.port.mk>
