# New ports collection makefile for:	fplib
# Date created:		2011-11-12
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fplib
PORTVERSION=	20100712
CATEGORIES=	audio
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Last.fm fingerprint library

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		mad:${PORTSDIR}/audio/libmad \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		tag:${PORTSDIR}/audio/taglib

CPPFLAGS+=	-I${LOCALBASE}/include
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes

PLIST_FILES=	bin/lastfmfpclient \
		lib/liblastfmfp.a \
		lib/liblastfmfp.so \
		lib/liblastfmfp.so.1 \
		lib/liblastfmfp.so.1.6.0

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(ADD_DEFINITIONS\)(.*)|\1(${CFLAGS} ${CPPFLAGS})|' \
		-e 's|\(OUTPUT_NAME lastfmfp\)_static|\1|' \
			${WRKSRC}/fplib/CMakeLists.txt
	@${REINPLACE_CMD} \
		-e 's|\(ADD_DEFINITIONS\)(.*)|\1(${CFLAGS} ${CPPFLAGS})|' \
		-e 's|^\(LINK_DIRECTORIES\)(.*)|\1(${LOCALBASE}/lib)|' \
		-e 's| lastfmfp_static| lastfmfp_shared|' \
			${WRKSRC}/lastfmfpclient/CMakeLists.txt

.include <bsd.port.mk>
