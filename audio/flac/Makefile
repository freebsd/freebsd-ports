# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flac
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg

USES=		iconv libtool pathfix pkgconfig tar:xz

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-sse \
		--with-ogg="${LOCALBASE}" \
		--disable-silent-rules \
		--disable-thorough-tests \
		--disable-xmms-plugin
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/share/doc && ${MV} ${DISTNAME} flac
	${REINPLACE_CMD} 's:%%PREFIX%%:${PREFIX}:' \
	    ${STAGEDIR}${PREFIX}/man/man1/flac.1
	${RM} ${STAGEDIR}${PREFIX}/man/man1/flac.1.bak

.include <bsd.port.mk>
