# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	pycadia
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_GENTOO:S/%SUBDIR%/distfiles/} \
		SF/nemysisfreebsdp/
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Home to vector gaming, Python style

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	pygtk2 libgnomeui
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	CHANGELOG README TODO gravity.txt

DESKTOP_ENTRIES="Pycadia" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

SUB_FILES=	${PORTNAME}.sh

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
	@(cd ${DATADIR} && ${CHMOD} 555 ${PORTNAME}.py spacewarpy.py vektoroids.py)
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${DATADIR}

	${INSTALL_DATA} ${WRKSRC}/pixmaps/logo1.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
