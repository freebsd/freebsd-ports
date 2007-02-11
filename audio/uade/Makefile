# New ports collection makefile for:	xmms-uade
# Date created:				12 Oct 2002
# Whom:					Martin Blapp <mbr@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-uade
PORTVERSION=	2.03
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.fi/uade/uade2/ \
		http://critical.ch/distfiles/
DISTNAME=	uade-${PORTVERSION}

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Unix Amiga Delitracker Emulator with XMMS Input plugin

RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		ao.3:${PORTSDIR}/audio/libao
BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:15

DOCSDIR=	${PREFIX}/share/doc/uade
CONFIGURE_ARGS=	--prefix=${X11BASE}/lib/xmms \
		--mandir=${MANPREFIX}/man/man1 \
		--without-audacious --no-debug

CONFIGURE_ENV=	SYSCFLAGS='${CFLAGS}'

WRKSRC=		${WRKDIR}/uade-${PORTVERSION}

MAN1=		uade123.1
PORTDOCS=	UAE-CREDITS UAE-README audio_emulation.txt design.tex \
		layers.eps layers.xfig \
		play_loop_state_diagram.dia play_loop_state_diagram.eps \
		play_loop_state_diagram.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

post-install:
		@${RM} -rf ${PREFIX}/share/uade2/players/S

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
