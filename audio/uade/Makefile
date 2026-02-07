PORTNAME=	uade
DISTVERSION=	3.05
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.fi/uade/uade3/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Unix Amiga Delitracker Emulator
WWW=		https://zakalwe.fi/uade/

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		vasmm68k_mot:devel/vasm
LIB_DEPENDS=	libao.so:audio/libao \
		libbencodetools.so:devel/bencodetools \
		libzakalwe.so:devel/libzakalwe

USES=		gmake localbase:ldflags pkgconfig python:build \
		shebangfix tar:bzip2

SHEBANG_FILES=	configure write_audio/generate_amiga_oscilloscope_view

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--mandir=${PREFIX}/share/man/man1 \
		--no-debug \
		--prefix=${PREFIX} \
		--without-write-audio
CONFIGURE_ENV=	PYTHON_INTERPRETER=${PYTHON_CMD} \
		SYSCFLAGS='${CFLAGS}'

SHEBANG_FILES=	configure src/frontends/mod2ogg/mod2ogg2.sh.in \
		write_audio/generate_amiga_oscilloscope_view
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS TEXTSCOPE
OPTIONS_DEFAULT=	TEXTSCOPE
OPTIONS_SUB=		yes

TEXTSCOPE_DESC=	Audio register debug mode

TEXTSCOPE_CONFIGURE_WITH=	text-scope

post-extract:
	@${RM} -r ${WRKSRC}/players/S

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -g||' ${WRKSRC}/write_audio/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/uade123 \
	${STAGEDIR}${PREFIX}/lib/libuade.so \
	${STAGEDIR}${PREFIX}/lib/uade/uadecore

.include <bsd.port.mk>
