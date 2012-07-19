# ex:ts=8
# Ports collection makefile for:	muse
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MuSE
PORTVERSION=	0.9.2
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	http://files.dyne.org/muse/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple Streaming Engine

LICENSE=	GPLv2

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg

OPTIONS_DEFINE=	X11 LAME SNDFILE DOCS
OPTIONS_DEFAULT=X11

USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-lubrify --disable-rpath
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_SYS_UIO_H ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}

MAN1=		muse.1
PORTDOCS=	AUTHORS ChangeLog NEWS KNOWN-BUGS README TODO USAGE
PLIST_FILES=	bin/muse
.for lang in es it
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/muse.mo
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_GNOME+=	gtk20
.else
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=--without-x --with-rubik
.endif

.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
.else
CONFIGURE_ENV+=	ac_cv_header_lame_lame_h=no
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/src/portaudio/pa_unix_oss.c
.if empty(PORT_OPTIONS:MSNDFILE)
	@${REINPLACE_CMD} -e '/sndfile >=/s|$$PKG_CONFIG|${FALSE}|' \
		${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
