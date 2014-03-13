# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flac
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg

USES=		pathfix pkgconfig tar:xz
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sse \
		--with-ogg="${LOCALBASE}" \
		--disable-silent-rules \
		--disable-thorough-tests \
		--disable-xmms-plugin

OPTIONS_DEFINE=	DOCS ICONV
OPTIONS_DEFAULT=ICONV

ICONV_USES=	iconv
ICONV_CPPFLAGS=	-I${ICONV_PREFIX}/include
ICONV_LDFLAGS=	-L${ICONV_PREFIX}/lib
ICONV_CONFIGURE_OFF=	am_cv_func_iconv=no

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

pre-patch:
	@${REINPLACE_CMD} 's:^docdir = $$(datadir)/doc/$$(PACKAGE)-$$(VERSION):docdir = $$(datadir)/doc/$$(PACKAGE):' \
		`find ${WRKSRC}/doc -name Makefile.in`

post-build:
	${REINPLACE_CMD} 's:%%PREFIX%%:${PREFIX}:' ${WRKSRC}/man/flac.1

regression-test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
