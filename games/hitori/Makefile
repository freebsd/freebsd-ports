# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	hitori
PORTVERSION=	0.3.2
CATEGORIES=	games
MASTER_SITES=	GNOME

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Logic game similar to Sudoku

LICENSE=	GPLv3 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=	Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=	${WRKSRC}/COPYING-DOCS
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	xml2po:${PORTSDIR}/textproc/gnome-doc-utils
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk30
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog MAINTAINERS NEWS README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|itlocaledir = $$(prefix)/$$(DATADIRNAME)/locale|itlocaledir = $$(prefix)/share/locale|' \
		${WRKSRC}/po/Makefile.in.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/icons/48x48/${PORTNAME}.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
