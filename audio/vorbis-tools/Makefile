PORTNAME=	vorbis-tools
PORTVERSION=	1.4.2
PORTREVISION=	3
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/vorbis/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Play, encode, and manage Ogg Vorbis files
WWW=		https://xiph.org/vorbis/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libcurl.so:ftp/curl \
		libFLAC.so:audio/flac \
		libogg.so:audio/libogg \
		libopusfile.so:audio/opusfile \
		libspeex.so:audio/speex \
		libvorbis.so:audio/libvorbis

USES=		cpe iconv localbase:ldflags pkgconfig
CPE_VENDOR=	xiph
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
CONFIGURE_ARGS=	--without-kate

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/vorbis-tools
	${INSTALL_DATA} ${WRKSRC}/ogg123/ogg123rc-example \
	    ${STAGEDIR}${PREFIX}/share/examples/vorbis-tools/ogg123rc

.include <bsd.port.mk>
