# New ports collection makefile for:   avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	avifile
PORTVERSION=	0.6.0.20011220
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://avifile.sourceforge.net/ \
		http://ernie.eit.uni-kl.de/avifile/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.2/0-2/}admin
EXTRACT_SUFX=	.tgz

MAINTAINER=	holger@eit.uni-kl.de

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12

USE_QT_VER=	2
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.0.2/-2/}

USE_LIBTOOL=	yes
LIBTOOLFILES=	acinclude.m4
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_ARGS= --with-gnu-ld

PLIST_SUB=	LIB_VERSION="${LIB_VERSION}" VERSION="${VERSION}"

#CODEC_PORT=	${PORTSDIR}/graphics/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE

LIB_VERSION=	3
VERSION=	0.6
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
DIFF?=		/usr/bin/diff
FMT?=		/usr/bin/fmt

# compilation optimizations
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--enable-release
.endif

# libmad
.if !defined(WITHOUT_MAD)
PLIST_SUB+=	MAD=""
.else
CONFIGURE_ARGS+=	--disable-mad

PLIST_SUB+=	MAD="@comment "
.endif

# libvorbis; thus, libogg
.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS=	vorbis.1:${PORTSDIR}/audio/libvorbis

PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis

PLIST_SUB+=	VORBIS="@comment "
.endif

pre-everything::
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can disable compilation optimizations by defining"
	@${ECHO_MSG} "	WITHOUT_OPTIMIZED_CFLAGS."
.endif
.if !defined(WITHOUT_MAD)
	@${ECHO_MSG} "You can disable mad support by defining WITHOUT_MAD."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable vorbis support by defining WITHOUT_VORBIS."
.endif

pre-extract:
	@if [ -f ${LOCALBASE}/lib/libpth.so ]; then \
	  ${ECHO_MSG} "Error: This packet does not compile when the \
packet 'pth' is installed.";\
	  ${FALSE};\
	fi

pre-configure:
	@${PERL} -pi -e "s|-lqt|-lqt2|g;s|qt-mt|qt2-mt|g;\
		s|^(PACKAGE=avifile).*|\1|" \
		${WRKSRC}/configure
	@${PERL} -pi -e "s|-ljpeg|-L${LOCALBASE}/lib -ljpeg|g" \
		${WRKSRC}/samples/mjpeg_plugin/Makefile.in
	@${FIND} ${WRKSRC} \( -name Makefile.in -o -name configure \) | \
		${XARGS} ${PERL} -pi -e "s|AUTOCONF.*=.*|AUTOCONF=true|g;\
		s|ACLOCAL.*=.*|ACLOCAL=true|g;s|AUTOMAKE.*=.*|AUTOMAKE=true|g;\
		s|AUTOHEADER.*=.*|AUTOHEADER=true|g;\
		s|^INSTALL = .*|INSTALL=${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP}|g;\
		s|-release ..LT_RELEASE\)||"
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${PERL} -pi -e \
		"s|#include.*<malloc.h>|#include <stdlib.h>|g"

post-configure:
# Libtool fix code kindly provided by Mr. Maxim Sobolev <sobomax@FreeBSD.org>
	@${PERL} -pi -e \
		's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
			${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README
.endif
	@${FMT} < ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CONFIGURE_ARGS+=	--enable-x86opt --with-win32-path=${LOCALBASE}/lib/win32

PLIST_SUB+=	FFMPEG="" WIN32=""
.else
CONFIGURE_ARGS+=	--disable-x86opt --disable-win32 \
			--disable-ffmpeg --disable-ffmpeg-divx --disable-ffmpeg-ac3

PLIST_SUB+=	FFMPEG="@comment " WIN32="@comment "
.endif

.include <bsd.port.post.mk>
