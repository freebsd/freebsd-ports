# New Ports collection makefile for:	kye
# Date created:		17 July 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	kye
PORTVERSION=	1.0
CATEGORIES=	games python
MASTER_SITES=	http://games.moria.org.uk/kye/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	kye

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Puzzle game with arcade game elements

LICENSE=	GPLv2

OPTIONS_DEFINE=	DATA
OPTIONS_DEFAULT=	DATA

USE_GNOME=	pygtk2 librsvg2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
NO_BUILD=	yes

PORTDATA=	*
PORTDOCS=	NEWS README

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-install:
# Data
.if ${PORT_OPTIONS:MDATA}
	${INSTALL_DATA} ${WRKSRC}/kye-icon.png ${PREFIX}/share/pixmaps/Kye.png
	${INSTALL_DATA} ${WRKSRC}/kye-edit-icon.png ${PREFIX}/share/pixmaps/Kye-edit.png
.endif

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

# pkg-message
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
