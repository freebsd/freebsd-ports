PORTNAME=	fuel
DISTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	https://fuel-scm.org/files/releases/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	GUI Front-End to the Fossil SCM tool
WWW=		https://fuel-scm.org/fossil/home

LICENSE=	GPLv2

DEPRECATED=		Depends on deprecated www/qt5-webkit
EXPIRATION_DATE=	2023-12-31

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	fossil:devel/fossil

USES=		compiler:c++11-lang gmake qmake qt:5 shebangfix
USE_QT=		core gui network webkit widgets \
		buildtools:build linguisttools:build

SHEBANG_FILES=	intl/convert.sh
PLIST_FILES=	bin/fuel share/applications/fuel.desktop \
		share/icons/hicolor/256x256/apps/fuel.png

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr$$|${PREFIX}|' ${WRKSRC}/fuel.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/rsrc/fuel.desktop

.include <bsd.port.mk>
