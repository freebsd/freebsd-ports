# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	1.0
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.wiles.org/pub/mirrors/Vorbis/unix/ \
		http://www.oddsock.org/vorbis/unix/ \
		http://www.casterclub.com/vorbis/unix/ \
		http://www.math.utoledo.edu/~chaese/Vorbis/unix/

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		curl.2:${PORTSDIR}/ftp/curl \
		intl.4:${PORTSDIR}/devel/gettext \
		vorbis.2:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		ogg123.1 oggdec.1 oggenc.1 ogginfo.1 vcut.1 vorbiscomment.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/vorbis-tools
	${INSTALL_DATA} ${WRKSRC}/ogg123/ogg123rc-example \
		${PREFIX}/share/examples/vorbis-tools/ogg123rc

.include <bsd.port.mk>
