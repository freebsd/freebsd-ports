# $FreeBSD$

PORTNAME=	nomacs
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	SF/nomacs/nomacs-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	bsd@tuxproject.de
COMMENT=	Small, fast and free image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2 \
		sysinfo:${PORTSDIR}/devel/libsysinfo

USE_ZIP=	yes
USE_CMAKE=	yes
USE_QT4=	gui network linguist_build moc_build \
		qmake_build rcc_build uic_build
LDFLAGS+=	-lsysinfo -lkvm
# no RAW support for now.
CMAKE_ARGS+=	-DENABLE_RAW=0
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
