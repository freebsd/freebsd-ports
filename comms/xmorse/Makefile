PORTNAME=	xmorse
PORTVERSION=	20041125
PORTREVISION=	10
CATEGORIES=	comms hamradio
MASTER_SITES=	http://c2.com/morse/files/SourceCode/ \
		http://525183.serverbox.org/freebsd/xmorse/
DISTNAME=	m${PORTVERSION}

MAINTAINER=	sunrychen@gmail.com
COMMENT=	Fully automatic Morse code teaching machine
WWW=		http://c2.com/morse

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		sdl tar:tgz
USE_SDL=	sdl

PLIST_FILES=	bin/xmorse
NO_WRKSUBDIR=	yes
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
