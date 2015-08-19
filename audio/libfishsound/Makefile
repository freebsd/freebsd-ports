# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	libfishsound
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libfishsound/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Programing interface to decode/encode audio data

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libspeex.so:${PORTSDIR}/audio/speex \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

OPTIONS_DEFINE=	DOCS DOXYGEN

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig

PORTDOCS=	*

DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_IMPLIES=	DOCS

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| doc||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
