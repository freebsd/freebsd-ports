PORTNAME=	jp2a
DISTVERSION=	1.3.3
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/Talinx/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Converts JPG images to ASCII
WWW=		https://github.com/Talinx/jp2a

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexif.so:graphics/libexif \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp

USES=		jpeg localbase:ldflags ncurses pkgconfig tar:bz2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-assert \
		--disable-doxygen-doc

PLIST_FILES=	bin/jp2a \
		etc/bash_completion.d/jp2a \
		share/man/man1/jp2a.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jp2a ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/jp2a.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/bash/jp2a \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d

.include <bsd.port.mk>
