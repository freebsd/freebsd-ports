# New Ports collection makefile for:	nelly
# Date created:		16 July 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	nelly
PORTVERSION=	1.0
CATEGORIES=	games python
MASTER_SITES=	http://www.partiallydisassembled.net/nelly/ \
		http://media.pyweek.org/dl/2/rushed/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Nelly's Rooftop Garden, physics-based puzzle game

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>=0:${PORTSDIR}/devel/py-game \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl

OPTIONS_DEFINE=	DATA
OPTIONS_DEFAULT=	DATA

USE_PYTHON_RUN=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	README

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/*.py
	@(cd ${WRKSRC} && ${RM} *.py.bak)

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}

# Data
.if ${PORT_OPTIONS:MDATA}
.  for d in fonts levels textures
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor
.endif

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/textures/menu.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
