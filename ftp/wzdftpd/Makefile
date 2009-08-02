# New ports collection makefile for:	wzdftpd
# Date created:		2003-10-22
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	wzdftpd
PORTVERSION=	0.8.1
PORTREVISION=	5
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Modular FTP server configurable online using SITE commands

USE_AUTOTOOLS=	libtool:22
USE_RC_SUBR=	wzdftpd.sh
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig ltverhack
CONFIGURE_ARGS+=	--without-pam --disable-pgsql --disable-bonjour
CONFIGURE_ENV=	CPPFLAGS="${CPPLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	UTF8 "Enable UTF8 support" off \
		TCL "Enable TCL support" off \
		SSL "Enable OpenSSL support" off \
		GNUTLS "Enable gnutls support" on \
		IPV6 "Enable IPv6 support" on \
		PERL "Enable PERL support" off \
		MYSQL "Enable MYSQL backend" off \
		AVAHI "Enable Zeroconf support using Avahi" on \
		HOWL "Enable Zeroconf support using Howl" off

MAN1=	siteconfig.1 \
	siteuptime.1 \
	sitewho.1 \
	wzd-config.1
MAN8=	wzdftpd.8

.include <bsd.port.pre.mk>

.if defined(WITH_UTF8)
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=	--disable-utf8
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=	tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl='${PREFIX}/lib/tcl8.4'
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=	--without-tcl
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_SSL)
#USE_OPENSSL=	yes
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if !defined(WITH_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !defined(WITH_PERL)
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	PERL="@comment "
.else
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_AVAHI) || defined(WITH_HOWL)
PLIST_SUB+=	ZEROCONF=""
.else
PLIST_SUB+=	ZEROCONF="@comment "
.endif

.if defined(WITH_AVAHI) && !defined(WITH_HOWL)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus \
		avahi-core.6:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--with-zeroconf --enable-avahi
.endif

.if defined(WITH_HOWL) && !defined(WITH_AVAHI)
CFLAGS+=	-I${LOCALBASE}/include/howl
LIB_DEPENDS+=	howl.0:${PORTSDIR}/net/howl
CONFIGURE_ARGS+=	--with-zeroconf --enable-howl
.endif

PORTDOCS=	AUTHORS Permissions.ReadMeFirst README TLS.ReadMeFirst ChangeLog

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-patch:
	@${REINPLACE_CMD} -e "s|@HAVE_PERL_TRUE@|#|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
