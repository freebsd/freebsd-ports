# New ports collection makefile for:	games/zephulor
# Date created:			8 Aug 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	zephulor
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.hollowworks.com/downloads/adventuresonplanetzephulor/files/
DISTNAME=	${PORTNAME}-source

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Adventures on Planet Zephulor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

post-patch:
# Fix path to python interpreter
	@${REINPLACE_CMD} -e 's|#!.*python|#!${PYTHON_CMD}|' \
		${WRKSRC}/*.py ${WRKSRC}/maptool/*.py

# Make wrapper script
	@${ECHO_CMD} "#!/bin/sh" >> ${WRKSRC}/zephulor
	@${ECHO_CMD} '${PYTHON_CMD} ${DATADIR}/zephulor.py "$$@"' \
		>> ${WRKSRC}/zephulor

do-install:
# Wrapper script
	${INSTALL_SCRIPT} ${WRKSRC}/zephulor ${PREFIX}/bin

# Data directory
	${MKDIR} ${DATADIR}

# Executable scripts
.for f in chared maploadtool scnloadtool zephulor
	${INSTALL_SCRIPT} ${WRKSRC}/${f}.py ${DATADIR}
.endfor

# Scripts
.for f in game_config game_entities game_hud game_map game_menu \
	game_projectiles game_sound myimg
		${INSTALL_DATA} ${WRKSRC}/${f}.py ${DATADIR}
.endfor

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for f in README manual readme-chared readme-maploadtool \
		readme-scnloadtool
			${INSTALL_DATA} ${WRKSRC}/${f}.txt ${DOCSDIR}
.	endfor
.endif

# Maptool
	${MKDIR} ${DATADIR}/maptool

# Executable scripts
.for f in chared main
	${INSTALL_SCRIPT} ${WRKSRC}/maptool/${f}.py ${DATADIR}/maptool
.endfor

# Scripts
.for f in charmenu domenu game_entities game_map hud interface keymap myimg \
	tilemenu
		${INSTALL_DATA} ${WRKSRC}/maptool/${f}.py ${DATADIR}/maptool
.endfor

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/maptool
	${INSTALL_DATA} ${WRKSRC}/maptool/manual.txt ${DOCSDIR}/maptool
.endif

# Data
	${CP} -R ${WRKSRC}/data ${DATADIR}

# Fix wrong permissions
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	${FIND} ${DATADIR}/data -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${DATADIR}/data -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.mk>
