# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flac
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sse \
		--with-ogg="${LOCALBASE}" \
		--disable-thorough-tests \
		--disable-xmms-plugin
CPPFLAGS+=	-I${WRKSRC}/include
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	ICONV
OPTIONS_DEFAULT=ICONV

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-libiconv-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=--without-libiconv-prefix
.endif

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
.if ${PORT_OPTIONS:MDOCS}
MAKE_ENV+=	DOC=doc
.else
MAKE_ENV+=	DOC=""
.endif

USE_LDCONFIG=	yes
MAN1=		flac.1 metaflac.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

pre-patch:
	@${REINPLACE_CMD} 's:^docdir = $$(datadir)/doc/$$(PACKAGE)-$$(VERSION):docdir = $$(datadir)/doc/$$(PACKAGE):' \
		`find ${WRKSRC}/doc -name Makefile.in`

# "obj" is magic to our make(1)
post-configure:
	@${RM} -rf ${WRKSRC}/obj

post-build:
	${REINPLACE_CMD} 's:%%PREFIX%%:${PREFIX}:' ${WRKSRC}/man/flac.1

regression-test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
