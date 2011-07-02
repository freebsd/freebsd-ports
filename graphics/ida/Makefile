# New ports collection makefile for:	ida
# Date created:				Thu Aug 19 21:13:58 UTC 2004
# Whom:					Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ida
PORTVERSION=	2.08
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/fbida/
DISTNAME=	fbida-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast motif-based image viewer and editor

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		exif.12:${PORTSDIR}/graphics/libexif

OPTIONS=	GIF "Enable GIF support" on \
		PCD "Enable PhotoCD support" off \
		PNG "Enable PNG support" on \
		SANE "Enable SANE support" off \
		TIFF "Enable TIFF support" on \
		WEBP "Enable WebP suport" off

USE_MOTIF=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
MAKEFILE=	${WRKSRC}/GNUmakefile
MAKE_ARGS=	JPEG_VER=80 verbose=yes

MAN1=		exiftran.1 ida.1
PORTDOCS=	README TODO INSTALL
PLIST_FILES=	bin/exiftran bin/ida lib/X11/app-defaults/Ida

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GIF)
MAKE_ARGS+=	HAVE_LIBUNGIF=no
.else
LIB_DEPENDS+=	ungif.5:${PORTSDIR}/graphics/libungif
.endif

.if defined(WITH_PCD)
LIB_DEPENDS+=	pcd:${PORTSDIR}/graphics/libpcd
.else
MAKE_ARGS+=	HAVE_LIBPCD=no
.endif

.if defined(WITHOUT_PNG)
MAKE_ARGS+=	HAVE_LIBPNG=no
.else
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
.endif

.if defined(WITH_SANE)
LIB_DEPENDS+=	sane:${PORTSDIR}/graphics/sane-backends
.else
MAKE_ARGS+=	HAVE_LIBSANE=no
.endif

.if defined(WITHOUT_TIFF)
MAKE_ARGS+=	HAVE_LIBTIFF=no
.else
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.endif

.if defined(WITH_WEBP)
LIB_DEPENDS+=	webp:${PORTSDIR}/graphics/webp
.else
MAKE_ARGS+=	HAVE_LIBWEBP=no
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exiftran ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for a in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
