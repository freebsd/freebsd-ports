# New ports collection makefile for:	gcube
# Date created:			16 Jun 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	gcube
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://www.liquidx.org/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gamecube emulator

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTVERSION}
USE_GL=		yes
USE_SDL=	sdl
USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/gcube bin/gcmap bin/bin2dol bin/isopack bin/tplx
PORTDOCS=	ChangeLog README

FIXME=	general.h keys_sdl.h thpview.h video_sdl.c audio_sdl.c hw_gx.c gx.c \
	gx_texture.c gx_transform.c

post-patch:
	${REINPLACE_CMD} \
		-e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile.rules
	${REINPLACE_CMD} \
		-e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile.rules
	${REINPLACE_CMD} \
		-e 's|/usr/X11R6|${LOCALBASE}|' ${WRKSRC}/Makefile.rules
	${REINPLACE_CMD} \
		-e 's|%%LDFLAGS%%|${LDFLAGS}|' ${WRKSRC}/Makefile.rules
	${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcube ${PREFIX}/bin/gcube
	${INSTALL_PROGRAM} ${WRKSRC}/gcmap ${PREFIX}/bin/gcmap
	${INSTALL_PROGRAM} ${WRKSRC}/bin2dol ${PREFIX}/bin/bin2dol
	${INSTALL_PROGRAM} ${WRKSRC}/isopack ${PREFIX}/bin/isopack
	${INSTALL_PROGRAM} ${WRKSRC}/tplx ${PREFIX}/bin/tplx
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}/ChangeLog
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
