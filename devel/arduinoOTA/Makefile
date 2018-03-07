# $FreeBSD$

PORTNAME=	arduinoOTA
PORTVERSION=	1.2.0
CATEGORIES=	devel

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	OTA upload tool for Arduino/ESP8266

LICENSE=	GPLv3

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	arduino
GH_TAGNAME=	c2b8306

PLIST_FILES=	bin/${PORTNAME}
COMPILEINFO=	${OPSYS}${OSREL}-${ARCH}-${GH_TAGNAME}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} go build -o ${PORTNAME} -ldflags "-X main.compileInfo=${COMPILEINFO}" main.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
