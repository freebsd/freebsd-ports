# New ports collection makefile for:   avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	avifile
PORTVERSION=	0.60.20010920
CATEGORIES=	graphics
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/ 
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	holger@eit.uni-kl.de

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12
.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS=	vorbis.1:${PORTSDIR}/audio/libvorbis
.endif
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

ONLY_FOR_ARCHS=	i386
USE_QT_VER=	2
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.6

USE_AUTOMAKE_VER=15
USE_LIBTOOL=	yes
LIBTOOLFILES=	acinclude.m4
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-win32-path=${LOCALBASE}/lib/win32 \
		--enable-release --with-gnu-ld --enable-x86opt

PLIST_SUB=	LIB_VERSION="${LIB_VERSION}" VERSION="${VERSION}"
.if defined(WITHOUT_VORBIS)
PLIST_SUB+=	VORBIS="@comment "
.else
PLIST_SUB+=	VORBIS=""
.endif

#CODEC_PORT=	${PORTSDIR}/graphics/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE

LIB_VERSION=	3
VERSION=	0.6
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
DIFF?=		/usr/bin/diff
FMT?=		/usr/bin/fmt

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_VORBIS)
pre-everything::
	@${ECHO_MSG} "You can disable vorbis support by defining WITHOUT_VORBIS."
.endif

pre-extract:
	@if [ -f ${LOCALBASE}/lib/libpth.so ]; then \
	  ${ECHO_MSG} "Error: This packet does not compile when the \
packet 'pth' is installed.";\
	  ${FALSE};\
	fi
do-configure:
	(cd ${WRKSRC} && aclocal && ./autogen.sh &&\
	${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS})

# Libtool fix code kindly provided by Mr. Maxim Sobolev <sobomax@FreeBSD.org>
post-configure:
	@${PERL} -pi -e \
		's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
			${WRKSRC}/libtool
	${PATCH} ${PATCH_ARGS} -p0 < ${FILESDIR}/libwin32loader.patch

post-install:
	@${FMT} < ${PKGMESSAGE}

.include <bsd.port.post.mk>
