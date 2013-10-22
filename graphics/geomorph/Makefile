# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	geomorph
PORTVERSION=	0.50
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Height field generator and editor

LIB_DEPENDS=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext \
		png15:${PORTSDIR}/graphics/png

USES=		gmake pkgconfig
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix="${LOCALBASE}"

PLIST_SUB=	PORTVERSION=${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
CFLAGS+=	-O0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng15|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local/share/geomorph/GeoMorph.xpm|geomorph.xpm|' \
		${WRKSRC}/geomorph.desktop
	@${FIND} ${WRKSRC} -exec ${GREP} -q /usr/local/share/geomorph {} \; -print | \
		${XARGS} ${REINPLACE_CMD} -e 's|/usr/local/share/geomorph|${DATADIR}|'
	@${REINPLACE_CMD} -e 's|\$$HOME/geomorph|\$$HOME/.geomorph|' \
		${WRKSRC}/install-step* ${WRKSRC}/install-user ${WRKSRC}/update-rc
	@${REINPLACE_CMD} -e '/DEF_DIR_NAME/ s|geomorph|.geomorph|' \
		${WRKSRC}/src/app/globals.h ${WRKSRC}/src/hf/globals.h
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	@${RM} ${WRKSRC}/install*~

post-install:
	${INSTALL_DATA} ${WRKSRC}/geomorph.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/GeoMorph.xpm ${PREFIX}/share/pixmaps/geomorph.xpm

.include <bsd.port.post.mk>
