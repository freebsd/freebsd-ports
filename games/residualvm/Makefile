# Created by: Alexander Yerenkow <yerenkow@gmail.com>

PORTNAME=	residualvm
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	yerenkow@gmail.com
COMMENT=	ResidualVM allows you to indulge with classic games like Grim Fandango and Myst III

LICENSE=	BSD3CLAUSE GPLv2 GPLv3 ISCL LGPL21 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYING.BSD
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.FREEFONT
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING.ISC
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.MIT
LICENSE_FILE_ZLIB=	${WRKSRC}/COPYING.TINYGL

BROKEN_armv6=	fails to link: ld: libgrim.a has EABI version 0, but target residualvm has EABI version 5
BROKEN_armv7=	fails to link: ld: libgrim.a has EABI version 0, but target residualvm has EABI version 5

LIB_DEPENDS=	libmad.so:audio/libmad \
		libogg.so:audio/libogg \
		libvorbisfile.so:audio/libvorbis \
		libpng.so:graphics/png \
		libmpeg2.so:multimedia/libmpeg2 \
		libtheoradec.so:multimedia/libtheora \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gmake gl iconv jpeg sdl

USE_GITHUB=	yes

USE_GL=		glu glew gl
USE_SDL=	sdl2

HAS_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|{datarootdir}/man|{prefix}/man|' ${WRKSRC}/configure

.include <bsd.port.mk>
