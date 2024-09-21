PORTNAME=	agg
PORTVERSION=	2.5
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://distfiles.alpinelinux.org/distfiles/ \
		http://distfiles.lesslinux.org/ \
		http://gentoo.netnitco.net/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Quality Rendering Engine for C++
WWW=		http://www.antigrain.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copying

BROKEN=		Fails to build with freetype2 2.13.3, PR 281321, error: assigning to 'char *' from 'unsigned char *' converts between pointers to integer types where one is of the unique plain 'char' type and the other is not

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		autoreconf cpe gmake libtool pathfix pkgconfig sdl xorg
CPE_VENDOR=	antigrain
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_SDL=	sdl
USE_XORG=	x11

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/_LDFLAGS/_LDADD/' ${WRKSRC}/examples/Makefile.am

.include <bsd.port.mk>
