PORTNAME=	filezilla
PORTVERSION=	3.55.1
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	https://download.filezilla-project.org/client/
DISTNAME=	FileZilla_${PORTVERSION}_src

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Fast and reliable cross-platform FTP, FTPS, and SFTP client
WWW=		https://filezilla-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libfilezilla.so:ftp/libfilezilla \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libidn.so:dns/libidn \
		libnettle.so:security/nettle \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++17-lang gmake gnome iconv:wchar_t libtool localbase \
		pkgconfig sqlite tar:bzip2
USE_GNOME=	cairo gtk30
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_WX=		3.0
WX_CONF_ARGS=	relative

OPTIONS_DEFINE=		DBUS NLS
OPTIONS_DEFAULT=	DBUS
OPTIONS_SUB=		yes

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
