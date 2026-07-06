PORTNAME=	drawy
PORTVERSION=	1.0.2
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/drawy/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Infinite whiteboard application
WWW=		https://apps.kde.org/drawy/

IGNORE_i386=	upstream does not test builds on i386

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake desktop-file-utils gettext kde:6 \
		pkgconfig qt:6 shared-mime-info tar:xz

USE_KDE=	config configwidgets coreaddons crash \
		i18n iconthemes syntaxhighlighting \
		widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base declarative
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
