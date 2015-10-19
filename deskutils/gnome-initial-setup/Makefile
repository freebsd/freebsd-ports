# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-initial-setup
PORTVERSION=	3.16.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	First boot setup tool for GNOME 3

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gdm>=3.0.0:${PORTSDIR}/x11/gdm
LIB_DEPENDS=	libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libaccountsservice.so:${PORTSDIR}/sysutils/accountsservice \
		libpwquality.so:${PORTSDIR}/security/libpwquality \
		libgweather-3.so:${PORTSDIR}/net/libgweather
RUN_DEPENDS=	gdm>=3.0.0:${PORTSDIR}/x11/gdm

PORTSCOUT=	limitw:1,even

USES=		autoreconf compiler:c++11-lib gettext gmake libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	KERBEROS
OPTIONS_DEFAULT=KERBEROS

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MKERBEROS}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-gnome-initial-setup_gis-account-page.c
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|krb5/krb5.h|krb5.h|g' \
			${WRKSRC}/gnome-initial-setup/pages/account/um-realm-manager.c

.include <bsd.port.mk>
