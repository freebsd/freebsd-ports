# Created by: ijliao
# $FreeBSD$

PORTNAME=	MuSE
PORTVERSION=	0.9.2
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	https://files.dyne.org/muse/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple Streaming Engine

LICENSE=	GPLv2

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

OPTIONS_DEFINE=	X11 LAME SNDFILE DOCS
OPTIONS_DEFAULT=X11

USES=		gettext gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-lubrify --disable-rpath

CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_SYS_UIO_H
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib -lintl

PORTDOCS=	AUTHORS ChangeLog NEWS KNOWN-BUGS README TODO USAGE
PLIST_FILES=	bin/muse man/man1/muse.1.gz
.for lang in es it
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/muse.mo
.endfor

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ENV=	ac_cv_header_lame_lame_h=no
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
X11_USE=		GNOME=gtk20
X11_CONFIGURE_OFF=	--without-x --with-rubik

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' \
		${WRKSRC}/src/portaudio/pa_unix_oss.c
post-patch-SNDFILE-off:
	@${REINPLACE_CMD} -e '/sndfile >=/s|$$PKG_CONFIG|${FALSE}|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
