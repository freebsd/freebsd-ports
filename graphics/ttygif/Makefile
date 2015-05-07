# $FreeBSD$

PORTNAME=	ttygif
PORTVERSION=	1.0.8
CATEGORIES=	graphics

MAINTAINER=	olivier@cochard.me
COMMENT=	Converts a ttyrec file into animated gif

LICENSE=	MIT

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_GITHUB=	yes
GH_ACCOUNT=	icholy

USES=		tar:bzip2 gmake

PLIST_FILES=	bin/${PORTNAME} \
		bin/concat

post-patch:
	@${REINPLACE_CMD} 's:\#\!/bin/bash:\#\!/bin/sh:' ${WRKSRC}/concat.sh
	@${REINPLACE_CMD} 's:gcc:${CC}:' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/concat.sh ${STAGEDIR}${PREFIX}/bin/concat

.include <bsd.port.mk>
