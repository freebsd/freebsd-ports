# New ports collection makefile for: BillardGL
# Date created:		02 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	BillardGL
PORTVERSION=	1.75
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}%20${PORTVERSION}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-LP-010.zip \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	${PORTNAME:L}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	OpenGL pool billiard simulation

LICENSE=	GPLv2

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_DOS2UNIX=	Makefile
USE_GMAKE=	yes
USE_XORG=	xmu xext x11 xi
USE_GL=		glut

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}_48.png \
		share/pixmaps/${PORTNAME}_64.png \
		share/pixmaps/${PORTNAME}_72.png \
		share/pixmaps/${PORTNAME}_96.png

PORTDATA=	*
PORTDOCS=	README

OPTIONS_DEFINE=	LANG
LANG_DESC=	Install additional Language
OPTIONS_DEFAULT=	LANG

.include <bsd.port.options.mk>

post-patch:
# Fix data location
	@${REINPLACE_CMD} -e 's|/usr/share/BillardGL/|${DATADIR}/|' ${WRKSRC}/Namen.h

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
#	${MKDIR} ${DATADIR}
.for d in Texturen lang
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

# Pixmaps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png ${PREFIX}/share/pixmaps

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

# Additional Language
.if ${PORT_OPTIONS:MLANG}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-LP-010/*.lang ${DATADIR}/lang/
.endif

.include <bsd.port.mk>
