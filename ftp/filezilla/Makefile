PORTNAME=	filezilla
PORTVERSION=	3.68.1
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	LOCAL/pi
DISTNAME=	FileZilla_${PORTVERSION}_src

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Fast and reliable cross-platform FTP, FTPS, and SFTP client
WWW=		https://filezilla-project.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libfilezilla.so:ftp/libfilezilla \
		libharfbuzz.so:print/harfbuzz \
		libidn.so:dns/libidn \
		libnettle.so:security/nettle \
		libpugixml.so:textproc/pugixml

RUN_DEPENDS=	xdg-open:devel/xdg-utils

TEST_DEPENDS=	cppunit-config:devel/cppunit
TEST_TARGET=	check

USES=		compiler:c++17-lang gmake gnome iconv:wchar_t libtool localbase \
		pkgconfig sqlite tar:xz
USE_GNOME=	cairo gtk30 gdkpixbuf
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-fast-install
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_WX=		3.2
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

.include <bsd.port.mk>
