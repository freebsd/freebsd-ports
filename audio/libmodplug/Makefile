PORTNAME=	libmodplug
PORTVERSION=	0.8.9.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/modplug-xmms/libmodplug/${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	ModPlug mod-like music shared libraries
WWW=		https://modplug-xmms.sourceforge.net/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe
CPE_VENDOR=	konstanty_bialkowski
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include <bsd.port.mk>
