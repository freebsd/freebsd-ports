# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	chafa
PORTVERSION=	1.12.2
CATEGORIES=	graphics
MASTER_SITES=	https://hpjansson.org/chafa/releases/ \
		https://github.com/hpjansson/chafa/releases/download/${PORTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Character art facsimile generator

LICENSE=	GPLv3 LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libtiff.so:graphics/tiff \
		libwebpdemux.so:graphics/webp

USES=		cpe gettext-runtime gnome jpeg libtool magick:7 tar:xz
CPE_VENDOR=	chafa_project
USE_GNOME=	cairo gdkpixbuf2 glib20 librsvg2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}/html

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/share/man/man1

.include <bsd.port.mk>
