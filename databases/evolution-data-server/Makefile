# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution-data-server
PORTVERSION=	3.18.5
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gcr>=3.11:security/gcr \
		vapigen:lang/vala
LIB_DEPENDS=	libsoup-gnome-2.4.so:devel/libsoup-gnome \
		liboauth.so:net/liboauth \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgdata.so:devel/libgdata \
		libical.so:devel/libical \
		libnss3.so:security/nss \
		libtasn1.so:security/libtasn1 \
		libsecret-1.so:security/libsecret

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake gnome gperf libtool pathfix pkgconfig \
		sqlite tar:xz
# Unbreak mail/evolution with webkit-gtk3 on FreeBSD 8 and 9.  Normally
# this change would be done there, but it is not a C++ application, so it
# does not link directly to libstdc++ and adding the libstdc++ rpath to
# the executable does not work at runtime.
USES+=		compiler:c++11-lib
USE_GNOME=	gtk30 intltool introspection:build libxml2
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
USE_BDB=	5
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--with-openldap=yes \
		--disable-uoa \
		--enable-vala-bindings \
		--disable-gtk-doc \
		--with-libdb=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Evolution.DefaultSources.gschema.xml \
		org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution-data-server.addressbook.gschema.xml \
		org.gnome.evolution-data-server.calendar.gschema.xml \
		org.gnome.evolution-data-server.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	VERSION="3.18" EVO_VERSION="1.2"

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
WEATHER_DESC=	Weather calendar backend

WEATHER_LIB_DEPENDS=	libgweather-3.so:net/libgweather
WEATHER_CONFIGURE_ENABLE=	weather

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS} && exists(/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.else
CONFIGURE_ARGS+=	--without-krb5
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
