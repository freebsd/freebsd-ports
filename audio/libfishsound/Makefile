# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	libfishsound
PORTVERSION=	1.0.0
PORTREVISION=	2
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
USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	*
.endif

post-patch:
.if !${PORT_OPTIONS:MDOCS} || !${PORT_OPTIONS:MDOXYGEN}
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| doc||' ${WRKSRC}/Makefile.in
.endif

post-build:
	@${STRIP_CMD} ${WRKSRC}/src/libfishsound/.libs/libfishsound.so.4

.include <bsd.port.mk>
