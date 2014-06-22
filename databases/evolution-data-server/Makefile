# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server/Makefile,v 1.218 2013/03/09 09:12:37 kwm Exp $

PORTNAME=	evolution-data-server
PORTVERSION=	2.32.1
PORTREVISION=	8
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libical.so:${PORTSDIR}/devel/libical \
		libnss3.so:${PORTSDIR}/security/nss \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

USES=		bison gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gconf2 libxml2
USE_OPENLDAP=	yes
USE_SQLITE=	3
USE_BDB=	41+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-gnome-keyring=yes \
		--with-openldap=yes \
		--with-libdb=${LOCALBASE}
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_SUB=	VERSION="2.32" EVO_VERSION="1.2"

OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
OPTIONS_SUB=	yes
WEATHER_DESC=	Weather calendar backend

WEATHER_LIB_DEPENDS=	libgweather.so:${PORTSDIR}/net/libgweather
WEATHER_CONFIGURE_WITH=	weather
KERBEROS_CONFIGURE_ON=	--with-krb5=/usr
KERBEROS_CONFIGURE_OFF=	--without-krb5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
KRB5_LIB=	`/usr/bin/krb5-config gssapi --libs`
.endif

EDS_BDB_MSG=	"!!!WARNING!!!: Berkeley Database version is ${BDB_VER}.  If this is an upgrade, you may experience problems if you or any other Evolution-data-server users were previously using BDB_VER 41."

pre-everything::
	@if [ x"${BDB_VER}" != x"41" ]; then \
		${ECHO_MSG} ${EDS_BDB_MSG} | ${FMT} 75 79 ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g ; \
		s|heimlibs=".*"|heimlibs="${KRB5_LIB}"|g ; \
		s|-DGTK_DISABLE_DEPRECATED||g ; \
		s|-DG_DISABLE_DEPRECATED||g ; \
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
