PORTNAME=	scite
DISTVERSION=	5.5.0
CATEGORIES=	editors gnome
MASTER_SITES=	https://www.scintilla.org/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured SCIntilla based text editor for GTK/GNOME
WWW=		https://www.scintilla.org/SciTE.html

LICENSE=	SCINTILLA
LICENSE_NAME=	License for Lexilla, Scintilla and SciTE
LICENSE_FILE=	${WRKSRC}/../License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	liblexilla.so:textproc/lexilla \
		libscintilla.so:x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++20-lang desktop-file-utils gmake gnome pkgconfig \
		tar:tgz

USE_GNOME=	cairo gdkpixbuf2 gtk30
MAKEFILE=	makefile
MAKE_ARGS=	GTK3=1
.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=1
.endif

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

PORTDATA=	*.properties
PORTDOCS=	*.html *.jpg *.png

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
MAKE_ARGS+=	CLANG=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(SciteDefaultHome)|${DOCSDIR}|' \
		${WRKSRC}/../src/SciTEGlobal.properties

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/SciTE \
		${STAGEDIR}${PREFIX}/bin
	${LN} -sf SciTE ${STAGEDIR}${PREFIX}/bin/scite
	${INSTALL_MAN} ${WRKSRC}/../doc/scite.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/SciTE.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Sci48M.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/../src && \
		${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/../doc && \
		${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
