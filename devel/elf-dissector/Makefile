PORTNAME=	elf-dissector
DISTVERSION=	0.0.1
PORTREVISION=	3
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools for inspecting, analyzing and optimizing ELF files
WWW=		https://invent.kde.org/sdk/elf-dissector

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	binutils>=2.43:devel/binutils \
		gnulibiberty>=2.43:devel/gnulibiberty
LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libopcodes-2.43.so:devel/binutils

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime \
		kde:5 pkgconfig qt:5
USE_KDE=	itemmodels doctools:build ecm:build
KDE_INVENT=	942274185cc89fabf74f5f1efb886ecf210ab2fb sdk
USE_QT=	core gui widgets buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
