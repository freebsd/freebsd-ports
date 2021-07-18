PORTNAME=	geomorph
PORTVERSION=	0.60.1
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.60/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Height field generator and editor

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libpng.so:graphics/png

USES=		compiler:c++11-lang desktop-file-utils gl gmake pkgconfig \
		shebangfix
SHEBANG_FILES=	update-rc
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix="${LOCALBASE}"
USE_GCC=	yes # lots of severely broken code
CFLAGS+=	-fcommon

PLIST_SUB=	PORTVERSION=${PORTVERSION}
PORTDATA=	*

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' -e 's|/usr/local/share/geomorph|${DATADIR}|' {} \;
	@${REINPLACE_CMD} -e 's|\$$HOME/geomorph|\$$HOME/.geomorph|' \
		${WRKSRC}/install-step* ${WRKSRC}/install-user ${WRKSRC}/update-rc
	@${REINPLACE_CMD} -e '/DEF_DIR_NAME/ s|geomorph|.geomorph|' \
		${WRKSRC}/src/app/globals.h ${WRKSRC}/src/hf/globals.h
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
	${INSTALL_DATA} ${WRKSRC}/geomorph.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/GeoMorph.xpm ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
