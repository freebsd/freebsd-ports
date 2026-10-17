PORTNAME=	omawrite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	editors

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Dead-simple Markdown writing app built with Qt Quick
WWW=		https://github.com/omacom-io/omawrite

LICENSE=	MIT OFL11
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_OFL11=	${WRKSRC}/fonts/OFL.txt

RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		compiler:c++17-lang desktop-file-utils gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	omacom-io
USE_GL=		opengl
USE_QT=		base declarative

PLIST_FILES=	bin/omawrite \
		share/applications/omawrite.desktop \
		share/icons/hicolor/scalable/apps/omawrite.svg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omawrite ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pkgbuild/omawrite.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/pkgbuild/omawrite.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

do-test:
	@${MKDIR} ${WRKDIR}/tests
	cd ${WRKDIR}/tests && \
		${SETENVI} ${WRK_ENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} \
			${WRKSRC}/tests/tests.pro && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} && \
		${SETENV} QT_QPA_PLATFORM=offscreen ./tst_omawrite

.include <bsd.port.mk>
