# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	jp2a
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/Talinx/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Converts JPG images to ASCII

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png

USES=		jpeg localbase ncurses pkgconfig tar:bz2
USE_CSTD=	c99

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-doxygen-doc
CONFIGURE_ENV+=	bashcompdir=${STAGEDIR}${PREFIX}/etc/bash_completion.d
MAKE_ENV+=	bashcompdir=${STAGEDIR}${PREFIX}/etc/bash_completion.d

LDFLAGS+=	-lm

PLIST_FILES=	bin/jp2a \
		etc/bash_completion.d/jp2a \
		man/man1/jp2a.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jp2a ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/jp2a.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/bash/jp2a \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d

.include <bsd.port.mk>
