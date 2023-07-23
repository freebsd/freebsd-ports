PORTNAME=	libfishsound
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/libfishsound/ \
		https://ftp.osuosl.org/pub/xiph/releases/libfishsound/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Programming interface to decode/encode audio data
WWW=		https://www.xiph.org/fishsound/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libspeex.so:audio/speex \
		libvorbis.so:audio/libvorbis

USES=		libtool pathfix pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes
DOXYGEN_IMPLIES=DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| doc||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
