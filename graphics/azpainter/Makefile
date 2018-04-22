# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azpainter
PORTVERSION=	2.1.2
CATEGORIES=	graphics
MASTER_SITES=	OSDN/${PORTNAME}/69408

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

post-patch-NLS-on:
	@${REINPLACE_CMD} -e 's,tr/en\.mtr,tr/be.mtr &,' \
		${WRKSRC}/data/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's, install-dist_trdataDATA$$,,' \
		${WRKSRC}/data/Makefile.in

pre-build-NLS-on:
	${CP} -p ${FILESDIR}/be ${WRKSRC}/translation
	cd ${WRKSRC}/translation && ${CC} ${CFLAGS} -o mtrconv mtrconv.c
.for lang in be en ru uk
	cd ${WRKSRC}/translation && ./mtrconv ${lang} ../data/tr/${lang}.mtr
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
