# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.89b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/unix/sound/%SUBDIR%/
MASTER_SITE_SUBDIR=	lame
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME:S/-devel//}${PORTVERSION:S/b/beta/}

MAINTAINER=	cyrille.lefevre@laposte.net

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

# lame 3.89b builds ok w/ libvorbis-1.0.r1 but don't w/ r2.
# so, Ogg/Vorbis support should be disabled until this problem is fixed.
# see the following URL for details and followups :
# https://sourceforge.net/tracker/?func=detail&aid=462400&group_id=290&atid=100290
.if !defined(WITH_UNTESTED_VORBIS_FIX)
WITHOUT_VORBIS=	yes
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS=	vorbis.0:${PORTSDIR}/audio/libvorbis

# libvorbis sources are required wether or not the library is already installed.
DEPENDS=	${PORTSDIR}/audio/libvorbis:patch
.endif

WRKSRC=		${WRKDIR}/${PORTNAME:S/-devel//}-${PORTVERSION:S/b//}

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-nasm \
		--enable-mp3x \
		--enable-mp3rtp
USE_GMAKE=	yes
USE_LIBTOOL=	yes
WANT_GTK=	yes

MAN1=		lame.1

NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
.else
CONFIGURE_ARGS+=	--disable-gtktest
.endif

.if !defined(WITHOUT_VORBIS)
LIBVORBIS_SRC!=		cd ${PORTSDIR}/audio/libvorbis && ${MAKE} -V WRKSRC

CONFIGURE_ARGS+=	--with-vorbis
CONFIGURE_ENV+=		CONFIG_DEFS="${CONFIG_DEFS}" \
			CPPFLAGS="-I${LOCALBASE}/include \
				  -I${LIBVORBIS_SRC}/lib" \
			LDFLAGS="-L${LOCALBASE}/lib" \
			LIBS=-logg
CONFIG_DEFS=		-DUSE_FFT3DN # -DUSE_FFTSSE -DUSE_FFTFPU
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-devel//}
DOC_FILES=	API PRESETS.draft README TODO USAGE

pre-everything::
.if !defined(WITH_UNTESTED_VORBIS_FIX)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Vorbis support" \
		     "using an untested fix."
	@${ECHO_MSG} "hit Ctrl-C right now and use " \
		     "\"make WITH_UNTESTED_VORBIS_FIX=yes\""
	@${ECHO_MSG}
.else
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you don't want to compile with Vorbis support."
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITHOUT_VORBIS=yes\""
	@${ECHO_MSG}
.endif
.endif

.if defined(NOPORTDOCS)
do-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-exec
	@cd ${INSTALL_WRKSRC}/include && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-data
	@cd ${INSTALL_WRKSRC}/doc/man && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-data
.else
post-install: install-doc

install-doc:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
