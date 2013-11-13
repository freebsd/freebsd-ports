# Created by: Martin Blapp <mbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uade
PORTVERSION=	2.13
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.fi/uade/uade2/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Unix Amiga Delitracker Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao

USES=		gmake pkgconfig
HAS_CONFIGURE=	yes
USE_BZIP2=	yes

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

OPTIONS_DEFINE=	TEXTSCOPE FUSE XMMS DOCS

TEXTSCOPE_DESC=	Audio register debug mode
XMMS_DESC=	XMMS plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEXTSCOPE}
CONFIGURE_ARGS+=--with-text-scope
.endif

.if ${PORT_OPTIONS:MFUSE}
USES+=		fuse
PLIST_SUB+=	FUSE=""
.else
CONFIGURE_ARGS+=--without-uadefs
PLIST_SUB+=	FUSE="@comment "
.endif

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--without-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/players/S

post-patch:
	@${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
