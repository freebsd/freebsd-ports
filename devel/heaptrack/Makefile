PORTNAME=	heaptrack
DISTVERSION=	1.5.0
PORTREVISION=	7
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

PATCH_SITES=	https://invent.kde.org/sdk/heaptrack/-/commit/
PATCHFILES+=	2de688e02fbc5ff96fcf29ad3af962e8035824eb.patch:-p1 # Support KChart6
PATCHFILES+=	38fd1d7b0ff53a35ed7c4ef241c21c8c06e1efb2.patch:-p1 # Use QString for KConfigGroup names

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Heap memory profiler
WWW=		https://github.com/KDE/heaptrack

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libKChart6.so:graphics/kdiagram-qt6 \
		libboost_regex.so:devel/boost-libs \
		libdw.so:devel/elfutils \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang desktop-file-utils gl gettext-tools \
		kde:6 localbase qt:6 tar:xz xorg
USE_GL=		gl opengl # GLX
USE_KDE=	colorscheme completion config configwidgets coreaddons i18n \
		iconthemes itemmodels jobwidgets kio service solid \
		threadweaver widgetsaddons \
		ecm:build
USE_QT=		base svg
USE_XORG=	x11

CMAKE_ON=	HEAPTRACK_USE_QT6

.include <bsd.port.mk>
