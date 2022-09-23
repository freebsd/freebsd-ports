PORTNAME=	katomic
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games education kde kde-applications
MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/katomic/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 \
		shebangfix tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		dbusaddons guiaddons i18n iconthemes itemviews kio \
		libkdegames newstuff notifyconfig service widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools:build qmake:build
SHEBANG_FILES=	src/katomic-levelset-upd.pl

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
