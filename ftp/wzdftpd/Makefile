# Created by: Roman Bogorodskiy
# $FreeBSD$

PORTNAME=	wzdftpd
PORTVERSION=	0.8.3
CATEGORIES=	ftp ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-sources/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular FTP server configurable online using SITE commands

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	ICONV IPV6 MYSQL PERL PGSQL SQLITE TCL
OPTIONS_RADIO=	TLS ZEROCONF
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_RADIO_ZEROCONF=	AVAHI HOWL
OPTIONS_DEFAULT=	AVAHI GNUTLS
HOWL_DESC=	Zeroconf support via Howl

USES=		pkgconfig
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	-I m4 -I ac-helpers
AUTOMAKE_ARGS=	--add-missing --copy
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR} --without-pam --disable-bonjour
USE_LDCONFIG=	yes

USE_RC_SUBR=	wzdftpd

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		siteconfig.1 siteuptime.1 sitewho.1 wzd-config.1
MAN8=		wzdftpd.8

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
.else
CONFIGURE_ARGS+=	--disable-utf8
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=		tcl
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR}
PLIST_SUB+=	TCL=""
.else
PLIST_SUB+=	TCL="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}
MAN3+=		wzdftpd.3
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
PLIST_SUB+=	PGSQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	3
PLIST_SUB+=	SQLITE=""
.else
CONFIGURE_ARGS+=	--disable-sqlite3
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MAVAHI} || ${PORT_OPTIONS:MHOWL}
PLIST_SUB+=	ZEROCONF=""
.else
PLIST_SUB+=	ZEROCONF="@comment "
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libavahi-core.so:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--with-zeroconf --enable-avahi
.endif

.if ${PORT_OPTIONS:MHOWL}
LIB_DEPENDS+=	libhowl.so:${PORTSDIR}/net/howl
CPPFLAGS+=	-I${LOCALBASE}/include/howl
CONFIGURE_ARGS+=	--with-zeroconf --enable-howl
.endif

post-extract:
	@${RM} -f ${WRKSRC}/m4/libtool.m4
	@${RM} -f ${WRKSRC}/m4/lib-*.m4
	@${ECHO_CMD} -n > ${WRKSRC}/config.rpath

post-patch:
	@${REINPLACE_CMD} -e \
		'/Libs:/s|@PTHREAD_CFLAGS@|@LTLIBICONV@|' \
		${WRKSRC}/wzdftpd.pc.in
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
	(cd ${WRKSRC} && ${INSTALL_DATA} *.pc ${PREFIX}/libdata/pkgconfig )
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS Permissions.ReadMeFirst README \
	TLS.ReadMeFirst UPGRADING wzd_tls.cnf
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
