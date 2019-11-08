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

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	box:graphics/box

USES=		gnome python:2.7
USE_GNOME=	pygtk2
USE_PYTHON=	distutils autoplist
USE_LDCONFIG=	yes
NO_ARCH=	yes

PLIST_FILES=	share/pixmaps/${PORTNAME}.png
PORTDOCS=	ChangeLog

DESKTOP_ENTRIES="Boxer" "" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;" ""

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
