# New ports collection makefile for:	evolution-data-server
# Date created:				09 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server/Makefile,v 1.181 2009/10/18 04:17:46 marcus Exp $
#

PORTNAME=	evolution-data-server
PORTVERSION=	2.28.2
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		ical.43:${PORTSDIR}/devel/libical \
		nss3.1:${PORTSDIR}/security/nss \
		tasn1.4:${PORTSDIR}/security/libtasn1 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		gnome-keyring.0:${PORTSDIR}/security/gnome-keyring

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack ltverhack ltasneededhack \
		libglade2 libbonobo
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	libtool:22
USE_BDB=	41+
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-nss=yes \
		--enable-gnome-keyring=yes \
		--with-openldap=yes \
		--with-libdb=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_SUB=	VERSION="2.28" EVO_VERSION="1.2"

#OPTIONS=	IMAP4	"Enable experimental IMAP4 backend" off
OPTIONS=	WEATHER "Enable weather calendar backend" on

.include <bsd.port.pre.mk>

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL)
HEIMDAL_HOME?=	${LOCALBASE}
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} --with-krb5-includes=${HEIMDAL_HOME}/include
.elif !defined(NO_KERBEROS)
CONFIGURE_ARGS+=        --with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

#.if defined(WITH_IMAP4) || defined(PACKAGE_BUILDING)
#CONFIGURE_ARGS+=	--enable-imap4=yes
#PLIST_SUB+=		IMAP4=""
#.else
PLIST_SUB+=		IMAP4="@comment "
#.endif

.if defined(WITH_WEATHER)
LIB_DEPENDS+=		gweather.1:${PORTSDIR}/net/libgweather
CONFIGURE_ARGS+=	--with-weather
PLIST_SUB+=		WEATHER=""
.else
CONFIGURE_ARGS+=	--without-weather
PLIST_SUB+=		WEATHER="@comment "
.endif

EDS_BDB_MSG=	"!!!WARNING!!!: Berkeley Database version is ${BDB_VER}.  If this is an upgrade, you may experience problems if you or any other Evolution-data-server users were previously using BDB_VER 41."

pre-everything::
	@if [ x"${BDB_VER}" != x"41" ]; then \
		${ECHO_MSG} ${EDS_BDB_MSG} | ${FMT} 75 79 ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g ; \
		s|heimlibs=".*"|heimlibs="${KRB5_LIB}"|g ; \
		s|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
