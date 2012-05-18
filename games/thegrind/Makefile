# New Ports collection makefile for:	The Grind
# Date created:		2012-05-18
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	thegrind
PORTVERSION=	0.1.2
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/ld21/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A simple game about escaping from work

LICENSE=	GPLv2

LIB_DEPENDS=	radius:${PORTSDIR}/graphics/radius-engine \
		lua-5.1:${PORTSDIR}/lang/lua \
		png:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl sound
USE_GL=		glu
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/applications

PORTDATA=	*
PORTDOCS=	ChangeLog

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
