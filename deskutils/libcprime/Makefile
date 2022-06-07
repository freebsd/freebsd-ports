PORTNAME=	libcprime
DISTVERSION=	4.3.0
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
GL_COMMIT=	6a622256d9254c413017df03db21b87054b2fd16

.include <bsd.port.mk>
