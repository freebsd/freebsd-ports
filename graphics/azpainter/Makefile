# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azpainter
PORTVERSION=	2.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://aarnet.dl.osdn.jp/azpainter/68339/ \
		http://acc.dl.osdn.jp/azpainter/68339/ \
		http://c3sl.dl.osdn.jp/azpainter/68339/ \
		http://cznic.dl.osdn.jp/azpainter/68339/ \
		http://gigenet.dl.osdn.jp/azpainter/68339/ \
		http://iij.dl.osdn.jp/azpainter/68339/ \
		http://jaist.dl.osdn.jp/azpainter/68339/ \
		http://master.dl.osdn.jp/azpainter/68339/ \
		http://nchc.dl.osdn.jp/azpainter/68339/ \
		http://onet.dl.osdn.jp/azpainter/68339/ \
		http://osdn.dl.osdn.jp/azpainter/68339/ \
		http://pumath.dl.osdn.jp/azpainter/68339/ \
		http://rwthaachen.dl.osdn.jp/azpainter/68339/ \
		http://ymu.dl.osdn.jp/azpainter/68339/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	16-bit RGB full color painting application

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

BROKEN_powerpc64=	fails to build: mListDef.h: redefinition of typedef 'mList'

USES=		desktop-file-utils jpeg localbase shared-mime-info tar:xz
USE_XORG=	x11 xext xi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-freetype-dir=${LOCALBASE}/include/freetype2

PORTDOCS=	AUTHORS ChangeLog NEWS README README_ja manual

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's, install-dist_trdataDATA$$,,' \
		${WRKSRC}/data/Makefile.in

pre-build-NLS-on:
	cd ${WRKSRC}/translation && ${CC} ${CFLAGS} -o mtrconv mtrconv.c
.for lang in en ru uk
	cd ${WRKSRC}/translation && ./mtrconv ${lang} ../data/tr/${lang}.mtr
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
