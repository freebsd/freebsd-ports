# Created by: alepulver
# $FreeBSD$

PORTNAME=	filezilla
PORTVERSION=	3.14.1
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/FileZilla_Client/${PORTVERSION}
DISTNAME=	FileZilla_${PORTVERSION}_src

MAINTAINER=	matthew@reztek.cz
COMMENT=	Fast and reliable cross-platform FTP, FTPS, and SFTP client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils
BUILD_DEPENDS:=	${RUN_DEPENDS}
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libidn.so:${PORTSDIR}/dns/libidn \
		libpugixml.so:${PORTSDIR}/textproc/pugixml

BROKEN_FreeBSD_9=	requires C++14 complier, 9.x lacks C++11 standard library

INSTALLS_ICONS=	yes
USES=		compiler:c++14-lang gmake pkgconfig tar:bzip2
USE_SQLITE=	3
USE_WX=		3.0
WX_CONF_ARGS=	relative
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DBUS NLS
OPTIONS_DEFAULT=DBUS NLS
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_WITH=	dbus

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-locales

.if !defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--disable-manualupdatecheck
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "gcc"
.if ${ARCH} == i386 && ! ${CFLAGS:M-march=*}
# needed for __atomic_exchange_8, __atmoic_fetch_add_8, __atomic_store_8
CFLAGS+=	-march=i586
.endif
.endif

post-patch:
	${REINPLACE_CMD} -Ee 's|(dummy) wxrc|\1 ${WXRC_CMD:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
