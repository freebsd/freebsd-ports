# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	ttt
PORTVERSION=	2011.04
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/ttt/ \
		ftp://ftp.billsgames.com/unix/x/ttt/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple one or two player Tic Tac Toe game

LICENSE=	GPLv2

USE_AUTOTOOLS=	aclocal automake autoheader autoconf
AUTOMAKE_ARGS=	--add-missing --force
ALL_TARGET=	${PORTNAME}
USE_SDL=	mixer sdl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.bmp

PORTDATA=	*
PORTDOCS=	README

SUB_FILES=	${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}

# Data
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images sounds" ${DATADIR})

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/images/program_logo.bmp ${PREFIX}/share/pixmaps/${PORTNAME}.bmp

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
