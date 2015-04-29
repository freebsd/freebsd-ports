# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/evolution-data-server/Makefile 20048 2014-11-10 09:19:46Z gusi $

PORTNAME=	evolution-data-server
PORTVERSION=	3.12.11
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gcr>=3.11:${PORTSDIR}/security/gcr \
		vapigen:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		liboauth.so:${PORTSDIR}/net/liboauth \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libical.so:${PORTSDIR}/devel/libical \
		libnss3.so:${PORTSDIR}/security/nss \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

USES=		bison gettext gmake gperf libtool pathfix pkgconfig tar:xz
# Unbreak mail/evolution with webkit-gtk3 on FreeBSD 8 and 9.  Normally
# this change would be done there, but it is not a C++ application, so it
# does not link directly to libstdc++ and adding the libstdc++ rpath to
# the executable does not work at runtime.
USES+=		compiler:c++11-lib
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build \
		libxml2
USE_OPENLDAP=	yes
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
USE_BDB=	5
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--with-openldap=yes \
		--disable-uoa \
		--enable-vala-bindings \
		--with-libdb=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Evolution.DefaultSources.gschema.xml \
		org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution-data-server.addressbook.gschema.xml \
		org.gnome.evolution-data-server.calendar.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	VERSION="3.12" EVO_VERSION="1.2"

OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
WEATHER_DESC=	Weather calendar backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS} && exists(/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.else
CONFIGURE_ARGS+=	--without-krb5
.endif

.if ${PORT_OPTIONS:MWEATHER}
LIB_DEPENDS+=		libgweather-3.so:${PORTSDIR}/net/libgweather
CONFIGURE_ARGS+=	--enable-weather
PLIST_SUB+=		WEATHER=""
.else
CONFIGURE_ARGS+=	--disable-weather
PLIST_SUB+=		WEATHER="@comment "
.endif

EDS_BDB_MSG=	"!!!WARNING!!!: Berkeley Database version is ${BDB_VER}.  If this is an upgrade, you may experience problems if you or any other Evolution-data-server users were previously using BDB_VER 5."

pre-everything::
	@if [ x"${BDB_VER}" != x"5" ]; then \
		${ECHO_MSG} ${EDS_BDB_MSG} | ${FMT} 75 79 ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g ; \
		s|heimlibs=".*"|heimlibs="${KRB5_LIB}"|g ; \
		s|-Wl,--no-undefined||g ; \
		s|-Wnoexcept||g ; \
		s|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
