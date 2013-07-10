# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ida
PORTVERSION=	2.09
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.kraxel.org/releases/fbida/
DISTNAME=	fbida-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast motif-based image viewer and editor

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		exif:${PORTSDIR}/graphics/libexif

OPTIONS_DEFINE=	GIF PCF PNG SANE TIFF WEBP DOCS
OPTIONS_DEFAULT=	GIF PNG TIFF
PCD_DESC=	Enable PhotoCD support
SANE_DESC=	Enable SANE support

USE_PERL5_BUILD=yes
USES=		iconv gmake motif
MAKEFILE=	GNUmakefile
MAKE_ARGS=	JPEG_VER=80 verbose=yes
MAKE_JOBS_SAFE=	yes

LDFLAGS+=	-liconv

MAN1=		exiftran.1 ida.1
PORTDOCS=	README TODO INSTALL
PLIST_FILES=	bin/exiftran bin/ida lib/X11/app-defaults/Ida \
		${DESKTOPDIR:S/${PREFIX}\///}/ida.desktop
PLIST_DIRSTRY=	${DESKTOPDIR:S/${PREFIX}\///}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
.else
MAKE_ARGS+=	HAVE_LIBUNGIF=no
.endif

.if ${PORT_OPTIONS:MPCD}
LIB_DEPENDS+=	pcd:${PORTSDIR}/graphics/libpcd
.else
MAKE_ARGS+=	HAVE_LIBPCD=no
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.else
MAKE_ARGS+=	HAVE_LIBPNG=no
.endif

.if ${PORT_OPTIONS:MSANE}
LIB_DEPENDS+=	sane:${PORTSDIR}/graphics/sane-backends
.else
MAKE_ARGS+=	HAVE_LIBSANE=no
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.else
MAKE_ARGS+=	HAVE_LIBTIFF=no
.endif

.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=	webp:${PORTSDIR}/graphics/webp
.else
MAKE_ARGS+=	HAVE_LIBWEBP=no
.endif

post-install:
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/desktop/ida.desktop ${DESKTOPDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for a in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
