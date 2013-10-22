# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	gogglesmm
PORTVERSION=	0.12.7
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Music collection manager and player

LICENSE=	GPLv3

LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine \
		libtag.so:${PORTSDIR}/audio/taglib	\
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

OPTIONS_DEFINE=	DBUS CURL NLS NEWREMOTE GCRYPT DOCS
OPTIONS_SINGLE=	FOX
OPTIONS_SINGLE_FOX=	FOX16 FOX17
OPTIONS_DEFAULT=	DBUS CURL NEWREMOTE FOX16

FOX16_DESC=	Use stable branch of FOX
FOX17_DESC=	Use development branch of FOX
NEWREMOTE_DESC=	Use new remote player
GCRYPT_DESC=	Use libgcrypt for md5 calculation

OPTIONS_SUB=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man --prefix=${PREFIX}

USES=		pkgconfig gmake desktop-file-utils
USE_XZ=		yes
MAKE_ARGS=	CXX="${CXX}" LINK="${CXX}"
INSTALLS_ICONS=	yes

PORTDOCS=	README AUTHORS

FOX16_LIB_DEPENDS=	libFOX-1.6.so:${PORTSDIR}/x11-toolkits/fox16
FOX17_LIB_DEPENDS=	libFOX-1.7.so:${PORTSDIR}/x11-toolkits/fox17

GCRYPT_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_ON=	--with-md5=gcrypt
GCRYPT_CONFIGURE_OFF=	--with-md5=internal

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_OFF=	--with-dbus

CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_OFF=	--without-curl

NLS_USES=		gettext
NLS_LDFLAGS=		-lintl
NLS_CONFIGURE_OFF=	--disable-nls

NEWREMOTE_CONFIGURE_OFF=	--without-new-remote

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
