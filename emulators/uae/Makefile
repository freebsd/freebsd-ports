# New ports collection makefile for: uae
# Date created: 22 May 2000
# Whom: Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	uae
PORTVERSION=	0.8.25
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/sources/develop/ \
		http://www.electronghost.co.uk/~bernds/

MAINTAINER=	simond@irrelevant.org
COMMENT=	Amiga emulator

CONFLICTS=	e-uae-*

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259
CONFIGURE_ARGS=	--enable-sound --enable-vidmode --enable-dga
USE_XLIB=	yes
USE_GNOME=	gtk20

CFLAGS+=	${PTHREAD_CFLAGS}

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uae ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/readdisk ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/COMPATIBILITY ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README.PROGRAMMERS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/unix/README ${DOCSDIR}/README.unix
.endif
	@${MKDIR} ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/mousehack ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/timehack ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/transdisk ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/transrom ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control.info ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uae_rcli ${DATADIR}/amiga/
	${INSTALL_DATA} ${WRKSRC}/amiga/uaectrl ${DATADIR}/amiga/
	@${MKDIR} ${DATADIR}/amiga/devs
	@${MKDIR} ${DATADIR}/amiga/devs/AHI
	@${MKDIR} ${DATADIR}/amiga/devs/AudioModes
	${INSTALL_DATA} ${WRKSRC}/amiga/devs/AHI/uae.audio ${DATADIR}/amiga/devs/AHI/
	${INSTALL_DATA} ${WRKSRC}/amiga/devs/AudioModes/UAE ${DATADIR}/amiga/devs/AudioModes/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Doesn't build on FreeBSD < 5.x"
.endif

.include <bsd.port.post.mk>
