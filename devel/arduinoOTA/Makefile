PORTNAME=	arduinoOTA
PORTVERSION=	1.2.0
PORTREVISION=	29
CATEGORIES=	devel

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	OTA upload tool for Arduino/ESP8266
WWW=		https://www.arduino.cc

LICENSE=	GPLv3

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	arduino
GH_TAGNAME=	c2b8306

GO_BUILDFLAGS=	-ldflags "-X main.compileInfo=${COMPILEINFO}"

PLIST_FILES=	bin/${PORTNAME}
COMPILEINFO=	${OPSYS}${OSREL}-${ARCH}-${GH_TAGNAME}

.include <bsd.port.mk>
