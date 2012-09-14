# $FreeBSD$

PORTNAME=	mopesnake
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-pc-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Classic snake game in which you attempt to eat all the pain

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	TODO.txt index.html

SUB_FILES=	${PORTNAME}

post-patch:
# Fix path to python interpreter
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/*.py ${WRKSRC}/mopelib/*.py
	@(cd ${WRKSRC} && ${RM} *.py.bak mopelib/*py.bak)

.include <bsd.port.options.mk>

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}

# Data
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images mopelib music sounds" ${DATADIR})

# Pixmaps and version
	${INSTALL_DATA} ${WRKSRC}/doc/screenshot1.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/version ${DATADIR}

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
