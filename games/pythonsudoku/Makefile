# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pythonsudoku
PORTVERSION=	0.13
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/Python%20Sudoku/${PORTVERSION}/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Text and graphical program to create or resolve Sudokus

LICENSE=	GPLv2

LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}reportlab1>=0:${PORTSDIR}/print/py-reportlab1

USES=		tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	2
USE_PYDISTUTILS=yes
INSTALLS_ICONS=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	Changelog README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.png *.html *.txt *.css

DESKTOP_ENTRIES="Python Sudoku" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ""

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext:run

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/games|${PREFIX}/bin|; \
		s|/usr/share/games|${PREFIX}/share|' \
		${WRKSRC}/setup.cfg
	@${REINPLACE_CMD} -e  \
		's|#localedir = "DIRECTORY"|localedir = "${PREFIX}/share/locale"|' \
		${WRKSRC}/pythonsudoku/config.py
	@${FIND} ${WRKSRC} -name POTFILES -or -name *.po -or -name *.pot | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/lib/python2.4|${PYTHON_CMD}|'
	@${FIND} ${WRKSRC} -name "*.bak" -delete

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' \
		'/for lingua in linguas():/,/\["locale\/%s\/LC_MESSAGES\/pythonsudoku.mo" % lingua\]))/s/^/#/' \
		${WRKSRC}/setup.py
.endif

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && ${LN} -sf pysdk-gui.py ${PORTNAME}
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} *.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/)

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
