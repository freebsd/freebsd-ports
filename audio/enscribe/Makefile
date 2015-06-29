# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	enscribe
PORTVERSION=	0.1.0
PORTREVISION=	7
CATEGORIES=	audio graphics
MASTER_SITES=	http://www.coppercloudmusic.com/enscribe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create digital audio watermark images from photographic images

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libgd.so:${PORTSDIR}/graphics/gd \
		libpng.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		jpeg pkgconfig tar:tgz

LICENSE=	GPLv2

PORTDOCS=	README
PLIST_FILES=	bin/enscribe

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${BUILD_WRKSRC}; ${CC} ${CFLAGS} \
		`pkg-config --cflags --libs sndfile freetype2` \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-lgd -lpng -ljpeg -lm -lz \
		-o enscribe enscribe.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/enscribe ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
