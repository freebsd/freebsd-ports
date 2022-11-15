PORTNAME=	uconvert
DISTVERSION=	1.01
CATEGORIES=	emulators graphics

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Bitmap converter into Atari-specific formats
WWW=		https://github.com/mikrosk/uconvert

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick \
		libxml2.so:textproc/libxml2

USES=		compiler:c++17-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	mikrosk
GH_PROJECT=	uconvert
GH_TAGNAME=	v${DISTVERSION}

PLIST_FILES=	bin/uconvert

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uconvert ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
