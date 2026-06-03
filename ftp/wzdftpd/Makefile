PORTNAME=	wzdftpd
PORTVERSION=	0.8.3
PORTREVISION=	12
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-sources/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Modular FTP server configurable online using SITE commands
WWW=		https://sourceforge.net/projects/wzdftpd/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe gettext-tools libtool localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR} --datadir=${PREFIX}/lib \
		--disable-bonjour --disable-static
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_RC_SUBR=	wzdftpd

OPTIONS_DEFINE=	AVAHI DOCS ICONV IPV6 MYSQL PAM PERL PGSQL SQLITE TCL
OPTIONS_RADIO=	TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	AVAHI GNUTLS ICONV PAM PERL SQLITE
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
MYSQL_USES=		mysql
MYSQL_VARS=		IGNORE_WITH_MYSQL="80 81"

PAM_CONFIGURE_WITH=	pam

PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--disable-pgsql
PGSQL_USES=		pgsql

SQLITE_CONFIGURE_ENABLE=	sqlite3
SQLITE_USES=			sqlite:3

AVAHI_CONFIGURE_ON=	--with-zeroconf --enable-avahi
AVAHI_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libavahi-core.so:net/avahi-app

post-patch:
	@${TOUCH} ${WRKSRC}/config.rpath

# wzd.m4 gets installed into the wrong spot due to our --datadir hack
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/aclocal
	${MV} ${STAGEDIR}${PREFIX}/lib/aclocal/wzd.m4 ${STAGEDIR}${PREFIX}/share/aclocal
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/aclocal
	${INSTALL_DATA} ${WRKSRC}/*.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS Permissions.ReadMeFirst README \
	TLS.ReadMeFirst UPGRADING wzd_tls.cnf
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
