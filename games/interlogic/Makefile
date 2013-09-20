# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	interlogic
PORTVERSION=	0.30
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.3.0
DISTNAME=	interLOGIC-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Move colored balls through the maze connecting it with each other

USE_SDL=	image sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/interlogic

PLIST_FILES=	bin/interlogic

NO_STAGE=	yes
post-patch:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/missing # suppress autotools madness

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/interlogic ${PREFIX}/bin/

.include <bsd.port.mk>
