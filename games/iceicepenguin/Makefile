# $FreeBSD$

PORTNAME=	iceicepenguin
PORTVERSION=	1.5.1
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/Default/Ice%20Ice%20Penguin/  \
		SF/nemysisfreebsdp/:icons
DISTNAME=	iip.${DISTVERSION}-final
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_icons.zip:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Remake of an old SEGA Dreamcast game called Chu Chu Rocket

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/"ice ice penguin"

FETCH_ARGS?=	-Fpr
USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}_48.png \
		share/pixmaps/${PORTNAME}_64.png \
		share/pixmaps/${PORTNAME}_72.png \
		share/pixmaps/${PORTNAME}_96.png

PORTDATA=	*
PORTDOCS=	CHANGELOG.txt readme.txt

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}

# Data
	${MKDIR} ${DATADIR}
.for d in fonts gfx lvls menu sfx
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

# Pixmaps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png ${PREFIX}/share/pixmaps

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
