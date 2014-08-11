# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/evolution-data-server/Makefile 19797 2014-08-11 14:09:34Z gusi $

PORTNAME=	evolution-data-server
PORTVERSION=	3.12.5
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gcr>=3.11:${PORTSDIR}/security/gcr \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		liboauth.so:${PORTSDIR}/net/liboauth \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libical.so:${PORTSDIR}/devel/libical \
		libnss3.so:${PORTSDIR}/security/nss \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

USES=		bison gettext gmake libtool:keepla pathfix pkgconfig tar:xz
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

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
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
		s|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} '/^e_addressbook_factory_LDADD =/ \
		s/=/= -lgio-2.0 -lgobject-2.0 -lgthread-2.0 -lglib-2.0 $$(INTLLIBS)/' \
		${WRKSRC}/addressbook/libedata-book/Makefile.in
	@${REINPLACE_CMD} '/^test_interval_searches_LDADD =/s/=/= -lgthread-2.0/' \
		${WRKSRC}/calendar/backends/file/Makefile.in
	@${REINPLACE_CMD} -e '/^test_e_sexp_LDADD =/s/=/= -lical/' \
		-e '/^test_intervaltree_LDADD =/s/=/= -lical/' \
		-e '/^e_calendar_factory_LDADD =/s|=|= ../libecal/libecal-1.2.la -lical|' \
		${WRKSRC}/calendar/libedata-cal/Makefile.in
	@${REINPLACE_CMD} '/^camel_index_control_1_2_LDADD =/s/=/= -lgthread-2.0/' \
		${WRKSRC}/camel/Makefile.in
	@${REINPLACE_CMD} '/^test_imapx_LDADD =/s/=/= -lgobject-2.0 -lgthread-2.0/' \
		${WRKSRC}/camel/providers/imapx/Makefile.in
	@${REINPLACE_CMD} -e '/^test_contact_store_LDADD =/s|$$| ../addressbook/libebook/libebook-1.2.la|' \
		-e '/^test_name_selector_LDADD =/s|$$| ../camel/libcamel-1.2.la -lgthread-2.0|' \
		${WRKSRC}/libedataserverui/Makefile.in
	@${REINPLACE_CMD} '/^soap_test_LDADD =/s/=/= -lgthread-2.0/' \
		${WRKSRC}/servers/groupwise/Makefile.in

.include <bsd.port.mk>
