# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azpainter
DISTVERSION=	2.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://acc.dl.osdn.jp/azpainter/67130/ \
		http://cznic.dl.osdn.jp/azpainter/67130/ \
		http://gigenet.dl.osdn.jp/azpainter/67130/ \
		http://iij.dl.osdn.jp/azpainter/67130/ \
		http://jaist.dl.osdn.jp/azpainter/67130/ \
		http://onet.dl.osdn.jp/azpainter/67130/ \
		http://osdn.dl.osdn.jp/azpainter/67130/ \
		http://rwthaachen.dl.osdn.jp/azpainter/67130/ \
		http://ymu.dl.osdn.jp/azpainter/67130/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	16-bit RGB full color painting application

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		desktop-file-utils jpeg localbase tar:bzip2
USE_XORG=	x11 xext xi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-freetype-dir=${LOCALBASE}/include/freetype2

PORTDOCS=	AUTHORS ChangeLog NEWS README README.ja manual

OPTIONS_DEFINE=	DOCS

pre-build:
	${CP} -p ${FILESDIR}/?? ${WRKSRC}/translation
	cd ${WRKSRC}/translation && ${CC} ${CFLAGS} -o mtrconv mtrconv.c
.for lang in en ru uk
	cd ${WRKSRC}/translation && ./mtrconv ${lang} ../data/tr/${lang}.mtr
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
