# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azpainter
DISTVERSION=	2.1.7b4
CATEGORIES=	graphics
MASTER_SITES=	http://azsky2.html.xdomain.jp/arc/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	16-bit RGB full color painting application

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		compiler:c11 desktop-file-utils gmake jpeg pkgconfig \
		shared-mime-info tar:xz xorg
USE_XORG=	x11 xext xi
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" CC="${CC}"

PORTDOCS=	AUTHORS ChangeLog README README_ja manual_ja.html

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--debug
.endif

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/\/tr/d' ${WRKSRC}/Makefile.in

pre-build-NLS-on:
	cd ${WRKSRC}/translation && ${CC} ${CFLAGS} -o mtrconv mtrconv.c
.for lang in en ru uk
	cd ${WRKSRC}/translation && ./mtrconv ${lang} ../data/tr/${lang}.mtr
.endfor

.include <bsd.port.mk>
