# New ports collection makefile for:   avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	avifile
PORTVERSION=	0.60.20010429
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/ \
		http://divx.euro.ru/ \
		http://www.toon.eu.org/divx/
DISTFILES=	avifile-${PORTVERSION}.tar.gz \

MAINTAINER=	holger@eit.uni-kl.de

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

ONLY_FOR_ARCHS=	i386
USE_QT_VER=	2
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.6
LDCONFIG_DIRS=	%%PREFIX%%/lib/avifile

USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	acinclude.m4
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-win32-path=${LOCALBASE}/lib/win32 \
		--enable-release --with-gnu-ld

PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"

FMT=	/usr/bin/fmt

#CODEC_PORT=	${PORTSDIR}/graphics/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE

LIB_VERSION=	0
# Adhoc fix. First part.
# qt is there but configure is not finding it
# Therefore, it is avoiding this directories
# At least, on lioux's homesystem with qt 2.2.3
EXTRA_BUILD_DIR=	player samples/misc samples/qtrecompress

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
DIFF?=		/usr/bin/diff

.include <bsd.port.pre.mk>

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

post-build:
.for dir in ${EXTRA_BUILD_DIR}
	(cd ${WRKSRC}/${dir} && ${SETENV} ${MAKE_ENV} ${GMAKE})
.endfor

post-install:
	@${FMT} < ${PKGMESSAGE}
	@${INSTALL_DATA} ${WRKSRC}/lib/libaviplay.la ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/plugins/libaudiodec/libaudiodec.la ${PREFIX}/lib/avifile
	@${INSTALL_DATA} ${WRKSRC}/plugins/libmp3lame_audioenc/libmp3lame_audioenc.la ${PREFIX}/lib/avifile
	@${INSTALL_DATA} ${WRKSRC}/plugins/libmpeg_audiodec/libmpeg_audiodec.la ${PREFIX}/lib/avifile
	@${INSTALL_DATA} ${WRKSRC}/plugins/libwin32/libwin32.la ${PREFIX}/lib/avifile
#	@${LN} -sf libaviplay.so.${LIB_VERSION} ${PREFIX}/lib/libaviplay.so
# Adhoc fix. Second part.
# Install the missed applications.
.if exists(${PREFIX}/bin/aviplay)
	${DIFF} ${WRKSRC}/player/.libs/aviplay ${PREFIX}/bin > /dev/null || \
			${INSTALL_PROGRAM} ${WRKSRC}/player/.libs/aviplay \
				${PREFIX}/bin
.else
	${INSTALL_PROGRAM} ${WRKSRC}/player/.libs/aviplay ${PREFIX}/bin
.endif
.if exists(${PREFIX}/bin/benchmark)
	${DIFF} ${WRKSRC}/samples/misc/.libs/benchmark \
		${PREFIX}/bin > /dev/null || \
			${INSTALL_PROGRAM} \
				${WRKSRC}/samples/misc/.libs/benchmark \
					${PREFIX}/bin
.else
	${INSTALL_PROGRAM} ${WRKSRC}/samples/misc/.libs/benchmark \
		${PREFIX}/bin
.endif
.if exists(${PREFIX}/bin/qtrecompress)
	${DIFF} ${WRKSRC}/samples/qtrecompress/.libs/qtrecompress \
		${PREFIX}/bin > /dev/null || \
			${INSTALL_PROGRAM} ${WRKSRC}/samples/qtrecompress/.libs/qtrecompress ${PREFIX}/bin
.else
	${INSTALL_PROGRAM} ${WRKSRC}/samples/qtrecompress/.libs/qtrecompress \
		${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
