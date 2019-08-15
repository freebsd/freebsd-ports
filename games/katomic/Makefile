# $FreeBSD$

PORTNAME=	katomic
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications
MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 \
		shebangfix tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		dbusaddons ecm guiaddons i18n iconthemes itemviews kio \
		libkdegames newstuff notifyconfig service widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools_build qmake_build
SHEBANG_FILES=	katomic-levelset-upd.pl

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
