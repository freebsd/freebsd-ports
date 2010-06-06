# New ports collection makefile for:	uade
# Date created:				12 Oct 2002
# Whom:					Martin Blapp <mbr@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	uade
PORTVERSION=	2.13
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.fi/uade/uade2/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Unix Amiga Delitracker Emulator

LIB_DEPENDS=	ao.4:${PORTSDIR}/audio/libao

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

DOCSDIR=	${PREFIX}/share/doc/uade2
DATADIR=	${PREFIX}/share/uade2
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man/man1 \
		--no-debug --without-audacious

CONFIGURE_ENV=	SYSCFLAGS='${CFLAGS}'

MAN1=		uade123.1
PORTDOCS=	BUGS PLANS REDUNDANT_REPLAYERS UAE-CREDITS UAE-README \
		VERSION_CONTROL_TAGGING audio_emulation.txt design.tex \
		download.html faq.html layers.eps layers.xfig \
		play_loop_state_diagram.dia play_loop_state_diagram.eps \
		play_loop_state_diagram.txt uade.html

OPTIONS=	TEXT_SCOPE "Audio register debug mode" off \
		UADEFS "FUSE filesystem" off \
		XMMS "XMMS plugin" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TEXT_SCOPE)
CONFIGURE_ARGS+=--with-text-scope
.endif

.if !defined(WITHOUT_UADEFS)
LIB_DEPENDS+=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
MAN1+=		uadefs.1
PLIST_SUB+=	UADEFS=""
.else
CONFIGURE_ARGS+=--without-uadefs
PLIST_SUB+=	UADEFS="@comment "
.endif

.if !defined(WITHOUT_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--without-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/configure

post-install:
	@${RM} -rf ${DATADIR}/players/S

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
