# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hitori
PORTVERSION=	0.4.3
CATEGORIES=	games
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logic game similar to Sudoku

LICENSE=	GPLv3 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=	Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=	${WRKSRC}/COPYING-DOCS
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		xml2po:${PORTSDIR}/textproc/gnome-doc-utils \
		itstool:${PORTSDIR}/textproc/itstool

USES=		gmake pkgconfig tar:xz
USE_GNOME=	cairo glib20 gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog MAINTAINERS NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

# Wrong versioning upstream, Upstream use GTK3 in newer Versions
PORTSCOUT=	ignore:1

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|$$(DATADIRNAME)/locale|share/locale|' \
		${WRKSRC}/po/Makefile.in.in
.endif

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
	${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
