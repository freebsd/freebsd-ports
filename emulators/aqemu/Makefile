PORTNAME=	aqemu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt5 based QEMU frontend
WWW=		https://github.com/tobimensch/aqemu

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandoned upstream, uses Qt 5, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

LIB_DEPENDS=	libvncclient.so:net/libvncserver

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		buildtools:build qmake:build \
		core dbus gui network printsupport testlib widgets

USE_GITHUB=	yes
GH_ACCOUNT=	tobimensch

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
