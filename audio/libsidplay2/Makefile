PORTNAME=	libsidplay2
DISTVERSION=	2.1.1
PORTREVISION=	9
CATEGORIES=	audio emulators
MASTER_SITES=	SF/sidplay2/sidplay2/sidplay-libs-${DISTVERSION}
DISTNAME=	sidplay-libs-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to play Commodore 64 SID-tunes cycle accurately

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/libsidutils/src/ini/ini.cpp
	@${REINPLACE_CMD} '/^Libs:/s|\($${libdir}\)/lib\(.*\).la|-L\1 -l\2|' \
		${WRKSRC}/libsidplay/unix/libsidplay2.pc.in \
		${WRKSRC}/libsidutils/unix/libsidutils.pc.in

.include <bsd.port.mk>
