# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	uae
PORTVERSION=	0.8.29
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.amigaemulator.org/files/sources/develop/

MAINTAINER=	simond@irrelevant.org
COMMENT=	Commodore Amiga emulator

LICENSE=	GPLv2

CONFLICTS=	e-uae-[0-9]*

USE_BZIP2=	yes
USES=		gmake
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--enable-sound
USE_GNOME=	gtk20

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|build68kc|build68k|' \
		${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uae ${WRKSRC}/readdisk ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/COMPATIBILITY ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README.PROGRAMMERS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/unix/README ${DOCSDIR}/README.unix
.endif
	@${MKDIR} ${DATADIR}/amiga/devs/AHI
	@${MKDIR} ${DATADIR}/amiga/devs/AudioModes
	${INSTALL_DATA} ${WRKSRC}/amiga/mousehack ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/timehack ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/transdisk ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/transrom ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/uae-control.info ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/uae_rcli ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/uaectrl ${DATADIR}/amiga
	${INSTALL_DATA} ${WRKSRC}/amiga/devs/AHI/uae.audio \
		${DATADIR}/amiga/devs/AHI
	${INSTALL_DATA} ${WRKSRC}/amiga/devs/AudioModes/UAE \
		${DATADIR}/amiga/devs/AudioModes

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.mk>
