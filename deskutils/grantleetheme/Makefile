PORTNAME=	grantleetheme
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM grantleetheme
WWW=		https://www.kde.org/

LICENSE=	LGPL21

USES=		cmake gettext-tools kde:6 pkgconfig qt:6 tar:xz
# KDE Frameworks
USE_KDE=	colorscheme guiaddons i18n iconthemes newstuff \
		texttemplate xmlgui \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
