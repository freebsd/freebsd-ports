# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	rubrica
PORTVERSION=	2.1.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	BERLIOS
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addressbook for the GNOME 2 desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnotify.so:devel/libnotify
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme

USES=		desktop-file-utils gmake gnome libtool localbase pathfix \
		pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gconf2 gnomeprefix libglade2 intltool
USE_LDCONFIG=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

GCONF_SCHEMAS=	rubrica2.schemas

LIBS+=		-lm -lgthread-2.0

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g|-Wall|g ; \
		 s|-Wmissing-prototypes -g|-Wmissing-prototypes|g'
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|_Modifica|_Edit|' \
		-e 's|A_iuto|_Help|' \
		${WRKSRC}/interface/MainWindow.glade
	@${REINPLACE_CMD} -e \
		's|^Categories=.*|Categories=GNOME;Application;Office;System;Utility;|' \
		${WRKSRC}/rubrica2.desktop.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in

post-install:
	@${LN} -sf ${LOCALBASE}/share/icons/gnome \
		${STAGEDIR}${PREFIX}/share/pixmaps/rubrica2/22x22/hicolor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/reference/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/libRAL-reference

.include <bsd.port.mk>
