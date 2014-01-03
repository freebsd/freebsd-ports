# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	rubrica
PORTVERSION=	2.0.12
CATEGORIES=	deskutils gnome
MASTER_SITES=	BERLIOS
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Addressbook for the GNOME 2 desktop

LICENSE=	GPLv3

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USES=		desktop-file-utils gmake pathfix pkgconfig
USE_GNOME=	gconf2 gnomeprefix libglade2
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

GCONF_SCHEMAS=	rubrica2.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS ChangeLog

DOCSRCDIR2=	${WRKSRC}/doc/reference/html
DOCSDIR2=	${DOCSDIR}/doc/libRAL
DOC_FILES2=	*.*

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g|-Wall|g ; \
		 s|-Wmissing-prototypes -g|-Wmissing-prototypes|g'
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|_Modifica|_Edit|' \
		-e 's|A_iuto|_Help|' \
		${WRKSRC}/interface/MainWindow.glade
	${REINPLACE_CMD} -e 's|^Categories=.*|Categories=GNOME;Application;Office;System;Utility;|' \
		${WRKSRC}/rubrica2.desktop.in

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||g' ${WRKSRC}/Makefile.in
.endif

post-install:
	@${LN} -sf ${LOCALBASE}/share/icons/gnome \
		${STAGEDIR}${PREFIX}/share/pixmaps/rubrica2/22x22/hicolor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
