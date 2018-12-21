# Created by: Martin Blapp <mbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uade
PORTVERSION=	2.13
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.fi/uade/uade2/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Unix Amiga Delitracker Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libao.so:audio/libao

USES=		gmake pkgconfig tar:bzip2
HAS_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/uade2
DATADIR=	${PREFIX}/share/uade2

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man/man1 \
		--no-debug --without-audacious \
		--package-prefix=${STAGEDIR}

CONFIGURE_ENV=	SYSCFLAGS='${CFLAGS}'

PORTDOCS=	BUGS PLANS REDUNDANT_REPLAYERS UAE-CREDITS UAE-README \
		VERSION_CONTROL_TAGGING audio_emulation.txt design.tex \
		download.html faq.html layers.eps layers.xfig \
		play_loop_state_diagram.dia play_loop_state_diagram.eps \
		play_loop_state_diagram.txt uade.html

OPTIONS_DEFINE=	TEXTSCOPE FUSE DOCS
OPTIONS_SUB=	yes

TEXTSCOPE_DESC=	Audio register debug mode

TEXTSCOPE_CONFIGURE_WITH=	text-scope

FUSE_USES=		fuse
FUSE_CONFIGURE_WITH=	uadefs

post-extract:
	@${RM} -r ${WRKSRC}/players/S

post-patch:
	@${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/uade123 \
		${STAGEDIR}${PREFIX}/lib/uade2/uadecore

.include <bsd.port.mk>
