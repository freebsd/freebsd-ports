PORTNAME=	ttygif
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Converts a ttyrec file into animated gif

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	icholy

USES=		gmake magick:6,run

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's:gcc:${CC}:' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
