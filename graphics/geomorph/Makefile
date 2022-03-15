PORTNAME=	geomorph
PORTVERSION=	0.63
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Height field generator and editor

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libpng.so:graphics/png

USES=		autoreconf compiler:c++11-lang desktop-file-utils \
		gl gmake gnome libtool pkgconfig shebangfix
SHEBANG_FILES=	update-rc
USE_GNOME=	gtk20
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CFLAGS+=	-fcommon

PORTDATA=	*

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

pre-build:
# rebuild bundled linux binary
	cd ${WRKSRC}/scenes && ${RM} colman && ${CC} ${CFLAGS} ${LDFLAGS} -o colmap colmap.c

post-patch:
	@${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' -e 's|/usr/local/share/geomorph|${DATADIR}|' {} \;
	@${REINPLACE_CMD} -i '' -e 's|\$$HOME/geomorph|\$$HOME/.geomorph|' \
		${WRKSRC}/install-step* ${WRKSRC}/install-user ${WRKSRC}/update-rc
	@${REINPLACE_CMD} -i '' -e '/DEF_DIR_NAME/ s|geomorph|.geomorph|' \
		${WRKSRC}/src/app/globals.h ${WRKSRC}/src/hf/globals.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/geomorph.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/GeoMorph.xpm ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
