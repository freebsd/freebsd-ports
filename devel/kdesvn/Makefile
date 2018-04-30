# $FreeBSD$

PORTNAME=	kdesvn
DISTVERSION=	2.0.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frontend for Subversion

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libexpat.so:textproc/expat2 \
		libgdbm.so:databases/gdbm \
		libsvn_client-1.so:devel/subversion

CONFLICTS_INSTALL=	kdesvn-kde4 \
			qsvn-[0-9]*

USES=		bdb cmake:outsource kde:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons ecm i18n iconthemes itemviews jobwidgets \
		kio notifications parts service sonnet texteditor textwidgets \
		wallet widgetsaddons xmlgui
USE_QT5=	concurrent core dbus gui network sql widgets xml \
		buildtools_build qmake_build

post-patch:
	${REINPLACE_CMD} -e 's#%%EXECINFO%%#${EXECINFO_LDFLAGS} -lexecinfo#' \
		${PATCH_WRKSRC}/src/svnqt/cmake/FindSubversion.cmake

.include <bsd.port.mk>
