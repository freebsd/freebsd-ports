PORTNAME=	chinese-calendar
DISTVERSION=	1.0.3.r59
CATEGORIES=	chinese

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chinese traditional calendar
WWW=		https://github.com/WhiredPlanck/chinese-calendar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils gl qmake qt:5 shebangfix
USE_QT=		core gui network sql svg widgets buildtools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	WhiredPlanck
GH_TUPLE=	itay-grudev:SingleApplication:e99b8df:singleapplication/src/singleapplication

SHEBANG_FILES=	data/chinese-calendar-autostart

CXXFLAGS+=	-I${WRKSRC}/src

post-patch:
	@${FIND} ${WRKSRC} -name "*.desktop" -o -name "*.qss" | ${XARGS} ${REINPLACE_CMD} -i '' 's|/usr/|${PREFIX}/|'
	@cd ${WRKSRC} && ${REINPLACE_CMD} -i '' -e 's|/usr/|${PREFIX}/|g' \
		data/chinese-calendar-autostart \
		src/aboutdialog.ui \
		src/backup/aboutdialog.ui \
		src/chinesecalendar.cpp \
		src/dateitem.cpp \
		src/ccbo.cpp \
		src/main.cpp

post-install:
	@${MV} ${STAGEDIR}/etc/xdg ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
