PORTNAME=	seer-gdb
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7-20260913 # 2.7 is broken, see https://github.com/epasveer/seer/issues/550
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI frontend to gdb
WWW=		https://github.com/epasveer/seer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	gdb:devel/gdb

USES=		cmake compiler:c++17-lang gl qt:6
USE_QT=		base charts svg
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	epasveer
GH_PROJECT=	seer
GH_TAGNAME=	78282be

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/seergdb

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gdb|${LOCALBASE}/bin/gdb|' \
		${WRKSRC}/SeerGdbConfigPage.cpp \
		${WRKSRC}/SeerGdbWidget.cpp \
		${WRKSRC}/SeerMainWindow.cpp

.include <bsd.port.mk>
