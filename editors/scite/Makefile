# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scite
PORTVERSION=	3.7.4
CATEGORIES=	editors gnome
MASTER_SITES=	SF/scintilla/SciTE/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured SCIntilla based text editor for GTK/GNOME

LICENSE=	SCINTILLA
LICENSE_NAME=	License for Scintilla and SciTE
LICENSE_FILE=	${WRKSRC}/../License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libscintilla.so:x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:devel/xdg-utils

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USES=		compiler:c++11-lib desktop-file-utils gmake pkgconfig tar:tgz
USE_GNOME=	cairo gdkpixbuf2 gtk20
MAKEFILE=	makefile

PORTDATA=	*.properties
PORTDOCS=	*.html *.jpg *.png

post-patch:
	@${REINPLACE_CMD} -e 's| -Os||g' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|$$(SciteDefaultHome)|${DOCSDIR}|' \
		${WRKSRC}/../src/SciTEGlobal.properties

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/SciTE ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/../doc/scite.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/SciTE.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Sci48M.png ${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/../src && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/../doc && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
