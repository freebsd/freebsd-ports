# New ports collection makefile for: fceu-server
# Date created:		28 July 2007
# Whom:			Pontus Stenetorp <ninjin@kth.se>
#
# $FreeBSD$
#

PORTNAME=	fceu-server
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fceultra

MAINTAINER=	ninjin@kth.se
COMMENT=	The network play server for the NES/Famicom emulator fceu

CFLAGS+=	-DSOL_TCP=6
USE_GMAKE=	yes
USE_SDL=	sdl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=	does not build on FreeBSD 5.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/fceu-standard.conf|${ETCDIR}/fceu-standard.conf|g' \
		${WRKSRC}/server.cpp

do-install:
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/fceu-server.conf ${ETCDIR}/fceu-server.conf.sample
	@${INSTALL_PROGRAM} ${WRKSRC}/fceu-server ${PREFIX}/bin
	@[ -f ${ETCDIR}/fceu-standard.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/fceu-server.conf \
			${ETCDIR}/fceu-standard.conf

.include <bsd.port.post.mk>
