# New ports collection makefile for:	wzdftpd
# Date created:		2003-10-22
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	wzdftpd
PORTVERSION=	0.4.0
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Modular FTP server configurable online using SITE commands

USE_RC_SUBR=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_PERL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_ARGS+=	--without-mysql --without-pam
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	UFT8 "Enable UTF8 support" off \
		TCL "Enable TCL support" off \
		SSL "Enable OpenSSL support" on \
		IPV6 "Enable IPv6 support" on

MAN1=	siteconfig.1 \
	siteuptime.1 \
	sitewho.1 \
     	wzd-config.1
MAN8=	wzdftpd.8

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
CONFIGURE_ARGS+=	--with-openssl=/dev/null
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
PLIST_SUB+=	PERL="@comment "
.else
PLIST_SUB+=	PERL=""
.endif

PORTDOCS=	AUTHORS Permissions.ReadMeFirst README TLS.ReadMeFirst ChangeLog

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-install:
	${MV} ${PREFIX}/etc/wzd.cfg ${PREFIX}/etc/wzd.cfg.sample
	${MV} ${PREFIX}/etc/users ${PREFIX}/etc/users.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${SED} -e 's,PREFIX,${PREFIX},g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/wzdftpd.sh > ${PREFIX}/etc/rc.d/wzdftpd.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/wzdftpd.sh

.include <bsd.port.post.mk>
