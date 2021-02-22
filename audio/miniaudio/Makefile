# $FreeBSD$

PORTNAME=	miniaudio
PORTVERSION=	0.10.31
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C single header audio playback and capture library

LICENSE=	PD MIT
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	mackron
GH_TAGNAME=	53512c3

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/miniaudio.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/miniaudio.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
