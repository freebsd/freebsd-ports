# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vectoroids
PORTVERSION=	1.1.0
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/vectoroids/src/ \
		ftp://ftp.billsgames.com/unix/x/vectoroids/src/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Vector-based rock-shooting game similar to Asteroids

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_SDL=	image mixer sdl

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

MAN6=		${PORTNAME}.6

PORTDATA=	*
PORTDOCS=	CHANGES.txt README.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images music sounds" ${DATADIR})

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/images/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
