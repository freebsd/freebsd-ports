PORTNAME=	ttygif
PORTVERSION=	1.6.0
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Converts a ttyrec file into animated gif
WWW=		https://github.com/icholy/ttygif

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake magick:run

USE_GITHUB=	yes
GH_ACCOUNT=	icholy

PLIST_FILES=	bin/${PORTNAME}

# Upstream forgets to bump VERSION in its Makefile on release
post-patch:
	@${REINPLACE_CMD} 's:gcc:${CC}:' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s:^VERSION = .*:VERSION = '\"${PORTVERSION}\"':" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
