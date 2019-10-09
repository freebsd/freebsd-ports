# Created by: Roman Bogorodskiy
# $FreeBSD$

PORTNAME=	wzdftpd
PORTVERSION=	0.8.3
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-sources/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular FTP server configurable online using SITE commands

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gettext-tools libtool localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR} --without-pam --disable-bonjour
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_RC_SUBR=	wzdftpd

OPTIONS_DEFINE=	ICONV IPV6 MYSQL PERL PGSQL SQLITE TCL DOCS
OPTIONS_RADIO=	TLS ZEROCONF
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_RADIO_ZEROCONF=	AVAHI HOWL
OPTIONS_DEFAULT=	AVAHI GNUTLS
OPTIONS_SUB=	yes

ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
ICONV_CONFIGURE_OFF=	--disable-utf8
ICONV_USES=		iconv

TCL_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR}
TCL_CONFIGURE_OFF=	--without-tcl
TCL_USES=		tcl

OPENSSL_CONFIGURE_ENABLE=	openssl
OPENSSL_USES=		ssl

GNUTLS_CONFIGURE_ENABLE=	gnutls
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls

IPV6_CONFIGURE_ENABLE=	ipv6

PERL_CONFIGURE_ENABLE=	perl
PERL_USES=		perl5

MYSQL_CONFIGURE_ENABLE=	mysql
MYSQL_USE=		MYSQL=yes

PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--disable-pgsql
PGSQL_USES=		pgsql

SQLITE_CONFIGURE_ENABLE=	sqlite3
SQLITE_USES=			sqlite:3

AVAHI_CONFIGURE_ON=	--with-zeroconf --enable-avahi
AVAHI_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libavahi-core.so:net/avahi-app

HOWL_DESC=		Zeroconf support via Howl
HOWL_CONFIGURE_ON=	--with-zeroconf --enable-howl
HOWL_CPPFLAGS=		-I${LOCALBASE}/include/howl
HOWL_LIB_DEPENDS=	libhowl.so:net/howl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI} || ${PORT_OPTIONS:MHOWL}
PLIST_SUB+=	ZEROCONF=""
.else
PLIST_SUB+=	ZEROCONF="@comment "
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/config.rpath
	@${ECHO_CMD} "ACLOCAL_AMFLAGS= -I ac-helpers" >> ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e \
		'/LDFLAGS/s|@PTHREAD_CFLAGS@|@LTLIBICONV@|' \
		${WRKSRC}/libwzd-core/Makefile.am
	@${REINPLACE_CMD} -e \
		's|INSTALLDIRS=vendor|INSTALLPRIVLIB=$${prefix}/lib| ; \
		 /MAKE/s| install| pure_install|' \
		${WRKSRC}/libwzd-perl/Makefile.am
.for i in backends modules
	@${FIND} ${WRKSRC}/${i} -name "Makefile.am" | ${XARGS} \
		${REINPLACE_CMD} -e \
		'/^libdir/s|$${pkgdatadir}|$${prefix}/lib/wzdftpd|'
.endfor
	@${FIND} ${WRKSRC} -name "*_tls.c" | ${XARGS} ${REINPLACE_CMD} -e \
		'/<gcrypt.h>/d ; \
		 /gcry_control/d' \

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS Permissions.ReadMeFirst README \
	TLS.ReadMeFirst UPGRADING wzd_tls.cnf
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
