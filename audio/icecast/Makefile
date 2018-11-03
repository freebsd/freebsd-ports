# Created by: Chip Marshall <chip@eboai.org>
# $FreeBSD$

PORTNAME=	icecast
PORTVERSION=	2.4.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio net ipv6
MASTER_SITES=	http://downloads.xiph.org/releases/icecast/:source \
		http://svn.xiph.org/releases/icecast/:source \
		LOCAL/sunpoet/icecast:icon,source \
		http://www.icecast.org/:icon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source \
		favicon.ico:icon
DIST_SUBDIR=	icecast
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Streaming mp3/ogg-vorbis audio server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libshout.so:audio/libshout \
		libspeex.so:audio/speex \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libxslt.so:textproc/libxslt

OPTIONS_DEFINE=	DOCS

USES=		cpe gmake localbase

CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE}
GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message

CPE_VENDOR=	xiph

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/favicon.ico ${STAGEDIR}${DATADIR}/web/

.include <bsd.port.mk>
