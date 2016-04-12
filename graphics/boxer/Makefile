# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	boxer
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/boxc/${PORTNAME:C/^b/B/}%20-%20the%20Box%20GUI/${DISTNAME}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	box
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for Box the figure description language

LICENSE=	GPLv3

RUN_DEPENDS=	box:graphics/box

USE_GNOME=	pygtk2
USES=		python
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes

PLIST_FILES=	share/pixmaps/${PORTNAME}.png

PORTDOCS=	ChangeLog
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Boxer" "" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;" ""

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
