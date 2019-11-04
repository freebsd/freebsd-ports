# Created by: Joey Mingrone <joey@mingrone.org>
# $FreeBSD$

PORTNAME=	parcellite
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Lightweight GTK+ clipboard manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome localbase pkgconfig xorg
USE_GNOME=	glib20 gtk20 pango
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-appindicator

PORTDOCS=	AUTHORS ChangeLog README

LIBS+=		-lgio-2.0

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gmake gettext
NLS_USE=	GNOME=intltool
NLS_USES_OFF=	autoreconf
NLS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extrapatch-configure.ac
NLS_LIBS=	-lintl

SUB_FILES=	pkg-message

post-patch-NLS-on:
	@${REINPLACE_CMD} -e 's|$$(DATADIRNAME)/locale|share/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|@INTLTOOL_DESKTOP_RULE@||' \
		${WRKSRC}/data/Makefile.am
	@${REINPLACE_CMD} -e 's|_Name|Name|' -e 's|_Comment|Comment|' \
		${WRKSRC}/data/parcellite-startup.desktop.in \
		${WRKSRC}/data/parcellite.desktop.in

post-patch:
	@${REINPLACE_CMD} -e 's|/proc|/compat/linux/proc|g' \
		${WRKSRC}/src/utils.c

pre-build-NLS-off:
	@${REINPLACE_CMD} -e '/SUBDIRS = /s| po||' ${WRKSRC}/Makefile
	${MV} ${WRKSRC}/data/parcellite-startup.desktop.in \
		${WRKSRC}/data/parcellite-startup.desktop
	${MV} ${WRKSRC}/data/parcellite.desktop.in \
		${WRKSRC}/data/parcellite.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
