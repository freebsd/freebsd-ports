# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	enscribe
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	audio graphics
MASTER_SITES=	http://www.coppercloudmusic.com/enscribe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Create digital audio watermark images from photographic images

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libgd.so:${PORTSDIR}/graphics/gd \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		pkgconfig
NO_STAGE=	yes

LICENSE=	GPLv2

PORTDOCS=	README
PLIST_FILES=	bin/enscribe

.include <bsd.port.options.mk>

do-build:
	cd ${BUILD_WRKSRC}; ${CC} ${CFLAGS} \
		`pkg-config --cflags --libs sndfile freetype2` \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-lgd -lpng -ljpeg -lm -lz \
		-o enscribe enscribe.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/enscribe ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
