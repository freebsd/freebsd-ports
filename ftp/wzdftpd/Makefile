# New ports collection makefile for:	wzdftpd
# Date created:		2003-10-22
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	wzdftpd
PORTVERSION=	0.8.1
PORTREVISION=	8
CATEGORIES=	ftp ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-sources/${PORTNAME}-0.8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular FTP server configurable online using SITE commands

USE_AUTOTOOLS=	libtool
USE_RC_SUBR=	wzdftpd
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
USE_GNOME=	ltverhack
CONFIGURE_ARGS+=	--without-pam --disable-pgsql --disable-bonjour
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	UTF8 TCL OPENSSL GNUTLS IPV6 PERL MYSQL ZEROCONF
OPTIONS_SINGLE=	ZEROCONF
OPTIONS_SINGLE_ZEROCONF=	AVAHI HOWL
OPTIONS_DEFAULT=	GNUTLS IPV6 ZEROCONF AVAHI

UTF8_DESC=	Enable UTF8 support
ZEROCONF_DESC=	Enable Zeroconf support
HOWL_DESC=	Enable Zeroconf support using Howl
AVAHI_DESC=	Enable Zeroconf support using Avahi

MAN1=	siteconfig.1 \
	siteuptime.1 \
	sitewho.1 \
	wzd-config.1
MAN8=	wzdftpd.8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUTF8}
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=	--disable-utf8
.endif

.if ${PORT_OPTIONS:MTCL}
LIB_DEPENDS+=	tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl='${PREFIX}/lib/tcl8.4'
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=	--without-tcl
PLIST_SUB+=	TCL="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if !${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	PERL="@comment "
.else
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MZEROCONF}
PLIST_SUB+=	ZEROCONF=""
.else
PLIST_SUB+=	ZEROCONF="@comment "
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus \
		avahi-core.7:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--with-zeroconf --enable-avahi
.endif

.if ${PORT_OPTIONS:MHOWL}
CFLAGS+=	-I${LOCALBASE}/include/howl
LIB_DEPENDS+=	howl.0:${PORTSDIR}/net/howl
CONFIGURE_ARGS+=	--with-zeroconf --enable-howl
.endif

PORTDOCS=	AUTHORS Permissions.ReadMeFirst README TLS.ReadMeFirst ChangeLog

post-patch:
	@${REINPLACE_CMD} -e "s|@HAVE_PERL_TRUE@|#|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|" ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
