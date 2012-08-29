# New Ports collection makefile for:	Avoision
# Date created:		2012-05-17
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	avoision
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/avsn/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A simple collect-dots-avoid-blocks game

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/License.txt
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua \
		png15:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	${LOCALBASE}/include/radius.h:${PORTSDIR}/graphics/radius-engine \
		zip:${PORTSDIR}/archivers/zip

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

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
