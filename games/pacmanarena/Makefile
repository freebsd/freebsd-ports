# $FreeBSD$

PORTNAME=	pacmanarena
PORTVERSION=	0.15
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v0.0/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${DISTNAME:S/na/n-a/}.tar.bz2 \
		${PORTNAME:S/arena/-data/}-0.0.zip \
		${PORTNAME}_icons.tar.gz:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Pacman clone in full 3D with a few surprises

LICENSE=	GPLv2

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${PORTNAME:S/arena//}

GNU_CONFIGURE=	yes
USE_SDL=	mixer net sdl

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}_48.png \
		share/pixmaps/${PORTNAME}_64.png \
		share/pixmaps/${PORTNAME}_72.png \
		share/pixmaps/${PORTNAME}_96.png

PORTDATA=	*
PORTDOCS=	README

NO_STAGE=	yes
post-patch:
# Fix data location
	@${REINPLACE_CMD} -e 's|@prefix@|${DATADIR}|' \
	-e 's|@datadir@/pacman|${DATADIR}|'  ${WRKSRC}/Makefile.in

.include <bsd.port.options.mk>

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:S/arena//} ${PREFIX}/bin/${PORTNAME}

# Data
	${MKDIR} ${DATADIR}
.for d in gfx sfx
	@(cd ${WRKSRC}/../ && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

# Pixmaps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png ${PREFIX}/share/pixmaps

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
