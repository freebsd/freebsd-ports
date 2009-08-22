# New ports collection makefile for:	optipng
# Date created:				09 July 2003
# Whom:					Thomas Hurst <freaky@aagh.net>
#
# $FreeBSD$
#

PORTNAME=	optipng
PORTVERSION=	0.6.2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OptiPNG/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	An optimizer for PNG files

OPTIONS=	BUNDLED_LIBPNG	"Use bundled libpng"	off \
		BUNDLED_ZLIB	"Use bundled zlib"	off

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	scripts/unix.mak
ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/optipng
MAN1=		optipng.1
PORTDOCS=	caveat.txt history.txt manual.html manual.pdf manual.txt \
		png_optimization_guide.html thanks.html todo.txt

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	#
.ifndef(WITH_BUNDLED_LIBPNG)
CONFIGURE_ARGS+=	--with-system-libpng
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

.ifndef(WITH_BUNDLED_ZLIB)
CONFIGURE_ARGS+=	--with-system-zlib
.endif

do-configure:
	(cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/optipng ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/optipng.1 ${MAN1PREFIX}/man/man1/

post-install:
.ifndef NOPORTDOCS
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
