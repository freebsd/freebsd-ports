# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	1.4.0
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Play, encode, and manage Ogg Vorbis files

LIB_DEPENDS=	ao.4:${PORTSDIR}/audio/libao \
		curl.6:${PORTSDIR}/ftp/curl \
		FLAC.10:${PORTSDIR}/audio/flac \
		kate.3:${PORTSDIR}/multimedia/libkate \
		speex.1:${PORTSDIR}/audio/speex \
		vorbis.4:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_JOBS_SAFE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=    yes
PLIST_SUB+=     NLS=""
.else
USE_ICONV=	yes
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=     NLS="@comment "
.endif

MAN1=		ogg123.1 oggdec.1 oggenc.1 ogginfo.1 vcut.1 vorbiscomment.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/vorbis-tools
	${INSTALL_DATA} ${WRKSRC}/ogg123/ogg123rc-example \
		${PREFIX}/share/examples/vorbis-tools/ogg123rc

.include <bsd.port.mk>
