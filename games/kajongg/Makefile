# $FreeBSD$

PORTNAME=	kajongg
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	games kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted

NO_ARCH=	yes
USES=		cmake:outsource kde:4 python tar:xz shebangfix sqlite
USE_KDE=	kdelibs pykde4 automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DINSTALL_KAJONGG:BOOL=TRUE

SHEBANG_FILES=	src/kajongg.py \
		src/kajonggserver.py \
		src/kajonggtest.py

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
