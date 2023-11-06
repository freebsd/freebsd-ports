PORTNAME=	libmodplug
PORTVERSION=	0.8.9.1.r461
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	ModPlug mod-like music shared libraries
WWW=		https://modplug-xmms.sourceforge.net/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe
CPE_VENDOR=	konstanty_bialkowski
USE_GITHUB=	yes
GH_ACCOUNT=	ShiftMediaProject
GH_PROJECT=	modplug
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON

.include <bsd.port.mk>
