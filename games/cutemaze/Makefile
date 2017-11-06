# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cutemaze
PORTVERSION=	1.2.1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, top-down game in which mazes are randomly generated

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		qmake tar:bzip2
USE_QT5=	core gui svg imageformats_run widgets \
		linguisttools_build buildtools_build
INSTALLS_ICONS=	yes

PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -i '' '/qm.files/,/qm.path/s/^/#/' \
		${WRKSRC}/cutemaze.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for d in 16x16 22x22 scalable
	@(cd ${WRKSRC}/icons/oxygen && ${COPYTREE_SHARE} ${d} \
		${STAGEDIR}${PREFIX}/share/icons/oxygen)
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
