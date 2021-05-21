PORTNAME=	aqemu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt5 based QEMU frontend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvncclient.so:net/libvncserver

USES=		cmake compiler:c++11-lang qt:5
USE_QT=		buildtools_build qmake_build \
		core dbus gui network printsupport testlib widgets

USE_GITHUB=	yes
GH_ACCOUNT=	tobimensch

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
