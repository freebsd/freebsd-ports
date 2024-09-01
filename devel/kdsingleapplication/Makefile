PORTNAME=	kdsingleapplication
DISTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/KDAB/KDSingleApplication/releases/download/v${DISTVERSION}/

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	KDAB's helper class for single-instance policy applications
WWW=		https://github.com/KDAB/KDSingleApplication

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++17-lang qt:6
USE_QT=		base
USE_LDCONFIG=	yes

CMAKE_OFF=	CMAKE_CXX_EXTENSIONS \
		KDSingleApplication_EXAMPLES
CMAKE_ON=	KDSingleApplication_QT6

.include <bsd.port.mk>
