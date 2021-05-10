PORTNAME=	elf-dissector
DISTVERSION=	0.0.1
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools for inspecting, analyzing and optimizing ELF files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcapstone.so:devel/capstone4

BUILD_DEPENDS=	gnulibiberty>=2.33.1:devel/gnulibiberty \
		binutils>=2.33.1:devel/binutils

USES=		cmake compiler:c++17-lang \
		kde:5 pkgconfig qt:5

USE_QT=		core \
		buildtools_build qmake_build testlib_build
USE_KDE=	itemmodels \
		doctools_build ecm_build

KDE_INVENT=	92497fd2b887ff9ba1484450788db3910440213e sdk

.include <bsd.port.mk>


