# Created by: t.vanklaveren@student.utwente.nl
# $FreeBSD$

PORTNAME=	vorbis-tools
PORTVERSION=	1.4.0
PORTREVISION=	10
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Play, encode, and manage Ogg Vorbis files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libcurl.so:ftp/curl \
		libFLAC.so:audio/flac \
		libkate.so:multimedia/libkate \
		libspeex.so:audio/speex \
		libvorbis.so:audio/libvorbis

USES=		cpe iconv pkgconfig
CPE_VENDOR=	xiph
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/vorbis-tools
	${INSTALL_DATA} ${WRKSRC}/ogg123/ogg123rc-example \
	    ${STAGEDIR}${PREFIX}/share/examples/vorbis-tools/ogg123rc

.include <bsd.port.mk>
