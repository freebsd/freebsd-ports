PORTNAME=	icecast
PORTVERSION=	2.4.4
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	https://downloads.xiph.org/releases/icecast/:source \
		https://ftp.osuosl.org/pub/xiph/releases/icecast/:source \
		LOCAL/sunpoet/icecast:icon,source \
		https://github.com/xiph/Icecast-Server/raw/master/web/:icon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		favicon.ico:icon
DIST_SUBDIR=	icecast
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Streaming mp3/ogg-vorbis audio server
WWW=		https://icecast.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libogg.so:audio/libogg \
		libspeex.so:audio/speex \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		cpe gmake gnome localbase pkgconfig ssl
USE_GNOME=	libxml2 libxslt

GNU_CONFIGURE=	yes
USE_RC_SUBR=	icecast

CONFLICTS_INSTALL=	icecast-kh

SUB_FILES=	pkg-message

CPE_VENDOR=	xiph

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/favicon.ico ${STAGEDIR}${DATADIR}/web/

.include <bsd.port.mk>
