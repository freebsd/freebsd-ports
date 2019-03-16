# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	fuel
DISTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://fuel-scm.org/files/releases/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	GUI Front-End to the Fossil SCM tool

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	fossil:devel/fossil

USES=		compiler:c++11-lang gmake qmake qt:5 shebangfix
USE_QT=		core gui network webkit widgets \
		buildtools_build linguisttools_build

SHEBANG_FILES=	intl/convert.sh
PLIST_FILES=	bin/fuel share/applications/fuel.desktop \
		share/icons/hicolor/256x256/apps/fuel.png

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|/usr$$|${PREFIX}|' ${WRKSRC}/fuel.pro
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/rsrc/fuel.desktop

.include <bsd.port.mk>
