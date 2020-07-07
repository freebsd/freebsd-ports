# $FreeBSD$

PORTNAME=	bossa
PORTVERSION=	1.7.0
PORTREVISION=	9
CATEGORIES=	devel

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Flash programmer for Atmel SAM microcontrollers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	shumatech
GH_PROJECT=	${PORTNAME:tu}

USES=		compiler:c++11-lang gmake

CXXFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

ALL_TARGET=	bin/bossac

OPTIONS_DEFINE=		BOSSA BOSSASH
OPTIONS_DEFAULT=	BOSSASH
OPTIONS_SUB=		yes

BOSSA_DESC=		Include BOSSA GUI application using wxWidgets
BOSSA_ALL_TARGET=	bin/bossa
BOSSA_USE=		wx=3.0

BOSSASH_DESC=		Include BOSSA Shell
BOSSASH_USES=		readline
BOSSASH_ALL_TARGET=	bin/bossash

post-extract:
	${REINPLACE_CMD} -e 's/wx-config/$${WX_CONFIG}/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bossac ${STAGEDIR}${PREFIX}/bin/bossac

do-install-BOSSA-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bossa ${STAGEDIR}${PREFIX}/bin/bossa

do-install-BOSSASH-on:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bossash ${STAGEDIR}${PREFIX}/bin/bossash

.include <bsd.port.mk>
