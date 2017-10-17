# Created by: Max Khon
# $FreeBSD$

PORTNAME=	pgadmin3
PORTVERSION=	1.22.1
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	PGSQL/pgadmin3/release/v${PORTVERSION}/src
DIST_SUBDIR=	postgresql

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

LICENSE=	PostgreSQL

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

USES=		compiler:c++11-lib gettext gmake pgsql:9.0+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-version=${USE_WX} --enable-databasedesigner
CXXFLAGS=	-Wno-c++11-narrowing
USE_GNOME=	libxml2 libxslt
USE_WX=		3.0
USE_CXXSTD=	c++11
WX_COMPS=	wx
INSTALLS_ICONS=	yes
ICON_SIZES=	16 32

PLIST_FILES=	bin/pgadmin3 share/applications/pgadmin3.desktop
.for SZ in ${ICON_SIZES}
PLIST_FILES+=	share/icons/hicolor/${SZ}x${SZ}/apps/pgAdmin3.png
.endfor
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's,/wx-config,/${WX_CONFIG:T},' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,wxrc,wxrc-gtk2u-${WX_VERSION},' ${WRKSRC}/pgadmin/ui/embed-xrc
	@${REINPLACE_CMD} -e 's,/usr/bin/xterm,${LOCALBASE}/bin/xterm,' ${WRKSRC}/plugins.d/plugins.ini
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' ${WRKSRC}/pgadmin/ver_svn.sh
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
	${INSTALL_DATA} ${WRKSRC}/pgadmin/include/images/pgAdmin3-${SZ}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/pgAdmin3.png
.endfor

.include <bsd.port.mk>
