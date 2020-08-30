# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$

PORTNAME=	e-uae
DISTVERSION=	0.8.29.w4
PORTREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	http://www.rcdrummond.net/uae/${DISTNAME}/
DISTNAME=	e-uae-0.8.29-WIP4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced version of UAE, the Amiga emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	uae-[0-9]*

USES=		gmake gnome sdl tar:bzip2
USE_GNOME=	gtk20
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl --with-sdl-gfx
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PORTDOCS=	ChangeLog README bsdsocket.txt cmd-line.txt \
		compiling.txt configuration.txt floppies.txt \
		joystick.txt keyboard.txt scsi.txt
PLIST_FILES=	bin/readdisk bin/uae

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e '\,X11/xkb/rules,s,/usr/X11R6/lib,${LOCALBASE}/share,' \
		-e 's,-W ,&-Wno-unused-parameter ,' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/uae ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/readdisk ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README docs/bsdsocket.txt \
		docs/cmd-line.txt docs/compiling.txt docs/configuration.txt \
		docs/floppies.txt docs/joystick.txt docs/keyboard.txt \
		docs/scsi.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
