# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flac
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec

LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg

USES=		pathfix
USE_AUTOTOOLS=	libtool
USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sse \
		--with-ogg="${LOCALBASE}" \
		--disable-silent-rules \
		--disable-thorough-tests \
		--disable-xmms-plugin

OPTIONS_DEFINE=	DOCS ICONV
OPTIONS_DEFAULT=ICONV

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

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

post-build:
	${REINPLACE_CMD} 's:%%PREFIX%%:${PREFIX}:' ${WRKSRC}/man/flac.1

regression-test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
