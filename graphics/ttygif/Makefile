# $FreeBSD$

PORTNAME=	ttygif
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Converts a ttyrec file into animated gif

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	convert:graphics/ImageMagick

USE_GITHUB=	yes
GH_ACCOUNT=	icholy

USES=		gmake

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's:gcc:${CC}:' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
