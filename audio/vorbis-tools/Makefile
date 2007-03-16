# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	1.1.1
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

PATCH_SITES=	http://sites.inka.de/~mips/unix/distfiles/
PATCHFILES=	vorbis-tools-1.1.1-flac-1.1.3.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Play, encode, and manage Ogg Vorbis files

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		curl.4:${PORTSDIR}/ftp/curl \
		FLAC.7:${PORTSDIR}/audio/flac \
		speex.1:${PORTSDIR}/audio/speex \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_AUTOTOOLS=	aclocal:19 autoconf:259 automake:19 libtool:15
USE_GETTEXT=	yes
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-vcut
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
