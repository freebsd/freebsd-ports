# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	4stattack
PORTVERSION=	2.1.4
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	SF/forcedattack/4stAttack/${PORTVERSION}/
DISTNAME=	4stAttack-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect four stones in a straight line

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

RUN_DEPENDS=	${PYGAME}

USES=		gnome python:2.7 shebangfix
SHEBANG_FILES=	4stattack.py
NO_ARCH=	yes

PORTDOCS=	changelog.txt credits.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 22x22 32x32 48x48 64x64

SUB_FILES=	${PORTNAME} pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
.for s in 16 22 32 48 64
	@cd ${WRKSRC}/kde/icons/${s}x${s} ; \
		${MV} forcedattack2.png ${PORTNAME}_${s}x${s}.png
.endfor

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data gui players" ${STAGEDIR}${DATADIR})
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
.for f in settings.ini *.ttf *.sh version
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKSRC}/kde/icons/${s}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
