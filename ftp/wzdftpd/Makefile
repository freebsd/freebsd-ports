# New ports collection makefile for:	wzdftpd
# Date created:		2003-10-22
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	wzdftpd
PORTVERSION=	0.5.3
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Modular FTP server configurable online using SITE commands

USE_RC_SUBR=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_ARGS+=	--without-pam --without-pgsql
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	UTF8 "Enable UTF8 support" off \
		TCL "Enable TCL support" off \
		SSL "Enable OpenSSL support" on \
		GNUTLS "Enable gnutls support" off \
		IPV6 "Enable IPv6 support" on \
		PERL "Enable PERL support" off \
		MYSQL "Enable MYSQL backend" off

MAN1=	siteconfig.1 \
	siteuptime.1 \
	sitewho.1 \
     	wzd-config.1
MAN8=	wzdftpd.8

.include <bsd.port.pre.mk>

.if defined(WITH_UTF8)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--enable-utf8
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
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
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
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

PORTDOCS=	AUTHORS Permissions.ReadMeFirst README TLS.ReadMeFirst ChangeLog

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-patch:
	@${REINPLACE_CMD} -e "s|@HAVE_PERL_TRUE@|#|g" ${WRKSRC}/Makefile.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e "s|PRIu64|\"llu\"|g" ${WRKSRC}/src/*.[cl]
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/wzdftpd.sh > ${PREFIX}/etc/rc.d/wzdftpd.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/wzdftpd.sh
	@if test ! -f ${PREFIX}/etc/wzd.cfg; then \
		${CP} ${PREFIX}/etc/wzd.cfg.sample ${PREFIX}/etc/wzd.cfg; \
	fi
	@if test ! -f ${PREFIX}/etc/users; then \
		${CP} ${PREFIX}/etc/users.sample ${PREFIX}/etc/users; \
	fi

.include <bsd.port.post.mk>
