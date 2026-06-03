PORTNAME=	scite
DISTVERSION=	5.5.8
CATEGORIES=	editors gnome
MASTER_SITES=	https://www.scintilla.org/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Full-featured SCIntilla based Text Editor for GTK/GNOME
WWW=		https://www.scintilla.org/SciTE.html

LICENSE=	SCINTILLA
LICENSE_NAME=	License for Lexilla, Scintilla and SciTE
LICENSE_FILE=	${WRKSRC}/scite/License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++20-lang desktop-file-utils gmake gnome pkgconfig \
		tar:tgz

USE_GNOME=	cairo gdkpixbuf gdkpixbufextra gtk30
MAKEFILE=	makefile
MAKE_ARGS=	GTK3=1
.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=1
.endif

WRKSRC=		${WRKDIR}

PORTDATA=	*.properties
PORTDOCS=	*.html *.jpg *.png

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
MAKE_ARGS+=	CLANG=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(SciteDefaultHome)|${DOCSDIR}|' \
		${WRKSRC}/scite/src/SciTEGlobal.properties

# SciTE's built process is to build, in order: Lexilla, Scintilla, then SciTE
# SciTE's Makefile doesn't do the first two, so I just do all 3 manually here.
do-build:
	cd ${WRKSRC}/lexilla/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}
	cd ${WRKSRC}/scintilla/gtk && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}
	cd ${WRKSRC}/scite/gtk && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

# SciTE's install target does not do a very good job of things, so this section is
# mostly to do all the parts it doesn't do.
do-install:
	cd ${WRKSRC}/scite/gtk && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${INSTALL_TARGET}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/SciTE \
		${STAGEDIR}${PREFIX}/lib/scite/libscintilla.so \
		${STAGEDIR}${PREFIX}/lib/scite/liblexilla.so
	${LN} -sf SciTE ${STAGEDIR}${PREFIX}/bin/scite
	${INSTALL_MAN} ${WRKSRC}/scite/doc/scite.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	(cd ${WRKSRC}/scite/src && \
		${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/scite/doc && \
		${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
