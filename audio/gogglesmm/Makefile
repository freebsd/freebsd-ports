# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	gogglesmm
PORTVERSION=	0.12.7
PORTREVISION=	3
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

USES=		pkgconfig gmake
USE_XZ=		yes
INSTALLS_ICONS=	yes
MAN1=		gogglesmm.1

PORTDOCS=	README AUTHORS

FOX16_LIB_DEPENDS=	FOX-1.6:${PORTSDIR}/x11-toolkits/fox16
FOX17_LIB_DEPENDS=	FOX-1.7:${PORTSDIR}/x11-toolkits/fox17

GCRYPT_LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_ON=	--with-md5=gcrypt
GCRYPT_CONFIGURE_OFF=	--with-md5=internal

DBUS_LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_OFF=	--with-dbus

CURL_LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_OFF=	--without-curl

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

NEWREMOTE_CONFIGURE_OFF=	--without-new-remote

.include <bsd.port.options.mk>

pre-install:
	@${MKDIR} ${PREFIX}/share/applications

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
