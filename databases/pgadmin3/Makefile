PORTNAME=	pgadmin3
DISTVERSION=	1.23.0.20230324
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	PostgreSQL database design and management system
WWW=		https://github.com/allentc/pgadmin3-lts/

LICENSE=	PostgreSQL

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		autoreconf:build compiler:c++11-lib gmake gnome pgsql
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	allentc
GH_PROJECT=	${PORTNAME}-lts
GH_TAGNAME=	1935837
USE_GNOME=	libxml2 libxslt
USE_WX=		3.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-databasedesigner --with-openssl --with-wx-version=${USE_WX}
CXXFLAGS+=	-Wno-c++11-narrowing

ICON_SIZES=	16 32
PLIST_FILES=	bin/pgadmin3 share/applications/pgadmin3.desktop
.for SZ in ${ICON_SIZES}
PLIST_FILES+=	share/icons/hicolor/${SZ}x${SZ}/apps/pgAdmin3.png
.endfor
PORTDATA=	*

OPTIONS_DEFINE=		DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_CONFIGURE_OFF=	--without-sphinx-build

pre-configure:
	@cd ${WRKSRC} ; ./bootstrap
	@${REINPLACE_CMD} -e 's,/wx-config,/${WX_CONFIG:T},' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,wxrc ,${WXRC_CMD:T} ,' ${WRKSRC}/pgadmin/ui/embed-xrc
	@${REINPLACE_CMD} -e 's,/usr/bin/xterm,${LOCALBASE}/bin/xterm,' ${WRKSRC}/plugins.d/plugins.ini
	@${REINPLACE_CMD} -e 's,Exec=/usr/bin/pgadmin3,Exec=${LOCALBASE}/bin/pgadmin3,'\
			  -e 's,Icon=/usr/share/pgadmin3/pgAdmin3.png,Icon=pgAdmin3,'\
			  -e '/^MimeType=/d'\
			  -e '/^DocPath=/d'\
		${WRKSRC}/pkg/pgadmin3.desktop

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/pkg/pgadmin3.desktop ${STAGEDIR}${PREFIX}/share/applications
.for SZ in ${ICON_SIZES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/pgadmin/include/images/pgAdmin3-${SZ}.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/pgAdmin3.png
.endfor

.include <bsd.port.mk>
