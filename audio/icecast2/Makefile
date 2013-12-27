# Created by: Chip Marshall <chip@eboai.org>
# $FreeBSD$

PORTNAME=	icecast2
PORTVERSION=	2.3.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio net ipv6
MASTER_SITES=	http://downloads.xiph.org/releases/icecast/:source \
		http://svn.xiph.org/releases/icecast/:source \
		LOCAL/sunpoet:source \
		http://www.icecast.org/:icon
DISTFILES=	icecast-${PORTVERSION}${EXTRACT_SUFX}:source \
		favicon.ico:icon
DIST_SUBDIR=	icecast
EXTRACT_ONLY=	icecast-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Streaming mp3/ogg-vorbis audio server

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libshout.so:${PORTSDIR}/audio/libshout2 \
		libspeex.so:${PORTSDIR}/audio/speex \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libxslt.so:${PORTSDIR}/textproc/libxslt

OPTIONS_DEFINE=	DOCS

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE}
GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
USES=		gmake
WRKSRC=		${WRKDIR}/icecast-${PORTVERSION}

DATADIR=	${PREFIX}/share/icecast
DOCSDIR=	${PREFIX}/share/doc/icecast
PORTDOCS=	*
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^SUBDIRS = / s| doc||; s| install-exec-am install-data-am| install-exec-am|' ${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/favicon.ico ${STAGEDIR}${DATADIR}/web/

.include <bsd.port.mk>
