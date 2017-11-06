# $FreeBSD$

PORTNAME=	filezilla
PORTVERSION=	3.24.0
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/FileZilla_Client/${PORTVERSION}
DISTNAME=	FileZilla_${PORTVERSION}_src

MAINTAINER=	rezny@FreeBSD.org
COMMENT=	Fast and reliable cross-platform FTP, FTPS, and SFTP client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xdg-open:devel/xdg-utils
BUILD_DEPENDS:=	${RUN_DEPENDS}
LIB_DEPENDS=	libfilezilla.so:ftp/libfilezilla \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libidn.so:dns/libidn \
		libnettle.so:security/nettle \
		libpugixml.so:textproc/pugixml \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

INSTALLS_ICONS=	yes
USES=		compiler:c++14-lang gmake iconv:wchar_t localbase pkgconfig sqlite tar:bzip2
USE_GNOME=	cairo gtk20
USE_WX=		3.0
WX_CONF_ARGS=	relative
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DBUS NLS
OPTIONS_DEFAULT=DBUS
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_WITH=	dbus

NLS_USES=		gettext
NLS_USES_OFF=		gettext-runtime
NLS_CONFIGURE_OFF=	--disable-locales

.if !defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--disable-manualupdatecheck
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|(dummy) wxrc|\1 ${WXRC_CMD:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
