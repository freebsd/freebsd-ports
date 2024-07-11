PORTNAME=	kdesvn
DISTVERSION=	2.1.0
PORTREVISION=	7
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frontend for Subversion
WWW=		https://projects.kde.org/projects/extragear/sdk/kdesvn

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Dwindling amount of users and streamlining of ports for the KDE Team to maintain
EXPIRATION_DATE=2024-12-31

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libexpat.so:textproc/expat2 \
		libgdbm.so:databases/gdbm
.if ${WITH_SUBVERSION_VER:U} == LTS
LIB_DEPENDS+=	libsvn_client-1.so:devel/subversion-lts
.else
LIB_DEPENDS+=	libsvn_client-1.so:devel/subversion
.endif

CONFLICTS_INSTALL=	qsvn

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons i18n iconthemes itemviews jobwidgets kio \
		notifications parts service solid sonnet texteditor \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network sql widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

PORTSCOUT=	ignore:1

LDFLAGS+=	-Wl,--as-needed

post-patch:
	${REINPLACE_CMD} -e 's#%%EXECINFO%%#${EXECINFO_LDFLAGS} -lexecinfo#' \
		${PATCH_WRKSRC}/src/svnqt/cmake/FindSubversion.cmake

.include <bsd.port.mk>
