# Created by: Piotr Kubaj <pkubaj@anongoth.pl>

PORTNAME=	avp
DISTVERSION=	20170505
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://icculus.org/avp/files/
EXTRACT_SUFX=	-a1.tar.gz

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source re-implementation of Alien versus Predator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gl openal sdl
USE_GL=		gl
USE_SDL=	sdl

LDFLAGS_i386=	-Wl,-znotext

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
