# New Ports collection makefile for:	mopesnake
# Date created:        2012-05-16
# Whom:                nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	mopesnake
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-pc-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A classic snake game in which you attempt to eat all the pain

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mopesnake \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	TODO.txt index.html

post-patch:
# Fix path to python interpreter
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/*.py ${WRKSRC}/mopelib/*.py
	@(cd ${WRKSRC} && ${RM} *.py.bak mopelib/*py.bak)

do-install:
# Scripts
	@${PRINTF} "#!/bin/sh\n\ncd ${DATADIR} &&\
		./${PORTNAME}.py\n" > ${WRKDIR}/${PORTNAME}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}

# Data
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images mopelib music sounds" ${DATADIR})

# Pixmaps and version
	${INSTALL_DATA} ${WRKSRC}/doc/screenshot1.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/version ${DATADIR}

# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
