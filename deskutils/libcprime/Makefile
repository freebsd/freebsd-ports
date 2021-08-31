PORTNAME=	libcprime
DISTVERSION=	4.2.2
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Library for bookmarking, saving recent activites, managing settings

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake qt:5
USE_QT=		buildtools_build core dbus gui network qmake_build widgets
USE_LDCONFIG=	yes
USE_GITLAB=	yes

GL_ACCOUNT=	CuboCore
GL_COMMIT=	a5d026eb116d714d1d5312210f914d0a0d4adb2d

.include <bsd.port.mk>
