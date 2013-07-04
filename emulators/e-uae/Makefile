# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$

PORTNAME=	e-uae
DISTVERSION=	0.8.29.w4
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/${DISTNAME}/
DISTNAME=	e-uae-0.8.29-WIP4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced version of UAE, the Amiga emulator

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

CONFLICTS=	uae-[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl --with-sdl-gfx
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	ChangeLog README bsdsocket.txt cmd-line.txt \
		compiling.txt configuration.txt floppies.txt \
		joystick.txt keyboard.txt scsi.txt
PLIST_FILES=	bin/readdisk bin/uae

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e '\,X11/xkb/rules,s,/usr/X11R6/lib,${LOCALBASE}/share,' \
		-e 's,-W ,&-Wno-unused-parameter ,' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/uae ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/readdisk ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/bsdsocket.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/cmd-line.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/compiling.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/configuration.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/floppies.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/joystick.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/keyboard.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/scsi.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
