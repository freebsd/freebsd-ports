PORTNAME=	kajongg
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://apps.kde.org/kajongg/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=16.6.0:devel/py-twisted@${PY_FLAVOR}
LIB_DEPENDS=	libKMahjongg6.so:games/libkmahjongg
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=16.6.0:devel/py-twisted@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang gettext kde:6 python \
		qt:6 shebangfix tar:xz
USE_KDE=	i18n \
		ecm:build
USE_QT=		base

SHEBANG_FILES=	src/kajongg.py \
		src/kajonggserver.py

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
