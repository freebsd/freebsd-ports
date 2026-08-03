PORTNAME=	klog
PORTVERSION=	2.5.3
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Simple Qt-based amateur radio logger
WWW=		https://github.com/ea4k/klog/wiki

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhamlib.so:comms/hamlib

USES=		compiler:c++17-lang gl cmake qt:6 xorg
USE_GITHUB=	yes
USE_GL=		opengl
USE_QT=		base declarative charts location positioning serialport \
		sqldriver-sqlite:run tools:build
GH_ACCOUNT=	ea4k
GH_PROJECT=	klog

.include <bsd.port.mk>
