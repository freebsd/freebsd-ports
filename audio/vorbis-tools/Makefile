# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	1.0.1
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/1.0.1/unix/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Play, encode, and manage Ogg Vorbis files

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		curl.2:${PORTSDIR}/ftp/curl \
		FLAC.5:${PORTSDIR}/audio/flac \
		intl.5:${PORTSDIR}/devel/gettext-old \
		speex.2:${PORTSDIR}/audio/speex \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		ogg123.1 oggdec.1 oggenc.1 ogginfo.1 vcut.1 vorbiscomment.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/vorbis-tools
	${INSTALL_DATA} ${WRKSRC}/ogg123/ogg123rc-example \
		${PREFIX}/share/examples/vorbis-tools/ogg123rc

.include <bsd.port.mk>
