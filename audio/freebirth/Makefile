# New ports collection makefile for:	freebirth
# Date created:				27 Dec 2001
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	freebirth
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.bitmechanic.com/projects/freebirth/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A bass synthesizer, step sequencer, and sample player

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=		"too unstable on FreeBSD 5.x"
.endif

pre-build:
	@${REINPLACE_CMD} -E -e 's|-g[[:space:]]+-O6|${CFLAGS}|; \
		s|gtk-config|${GTK_CONFIG}|; \
		s|^all: freebirth|all: Makefile.deps freebirth|; \
		s|gcc|${CC}|; \
		s|^LDFLAGS=|LDFLAGS=\$${LOADLIBES}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|include <machine/soundcard.h>|include <sys/soundcard.h>|' \
		${WRKSRC}/freebirth.c
	@${REINPLACE_CMD} -e 's|^#define FB_SAMPLES "."|#define FB_SAMPLES "${PREFIX}/share/freebirth"|' \
		${WRKSRC}/raw_wave.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebirth ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fusebirth ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/freebirth/raw
	${INSTALL_DATA} ${WRKSRC}/raw/*.raw ${PREFIX}/share/freebirth/raw

.include <bsd.port.post.mk>
