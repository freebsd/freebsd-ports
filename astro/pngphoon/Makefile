PORTNAME=	pngphoon
DISTVERSION=	1.3
CATEGORIES=	astro
MASTER_SITES=	https://svolli.de/software/pngphoon/

COMMENT=	PNG Phase of Moon
MAINTAINER=	fuz@FreeBSD.org
WWW=		https://svolli.de/software/pngphoon/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake localbase:ldflags tar:bz2

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/pngphoon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngphoon ${STAGEDIR}${PREFIX}/bin/pngphoon

.include <bsd.port.mk>
