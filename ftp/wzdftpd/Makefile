# New ports collection makefile for:	wzdftpd
# Date created:		2003-10-22
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	wzdftpd
PORTVERSION=	0.3.3
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Modular FTP server configurable online using SITE commands

USE_RC_SUBR=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN8=	wzdftpd.8

.if defined(PACKAGE_BUILDING)
WITH_UTF8=	yes
WITH_TCL=	yes
WITH_SSL=	yes
WITH_IPV6=	yes
.endif

.if defined(WITH_UTF8)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--enable-utf8
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=	tcl84:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl='${PREFIX}/include/tcl8.4:${PREFIX}/lib'
PLIST_SUB+=	TCL=""
.else
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-ssl
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

DOCS=		AUTHORS Permissions.ReadMeFirst README TLS.ReadMeFirst \
		ChangeLog src/DOCS_XFERLOG_FORMAT src/KNOWN_BUGS src/TODO

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

post-extract:
.if defined(WITH_TCL)
	@${REINPLACE_CMD} -e 's|-ltcl8.4|-ltcl84|g' ${WRKSRC}/configure
.endif

post-install:
	${MV} ${PREFIX}/etc/wzd.cfg ${PREFIX}/etc/wzd.cfg.sample
	${MV} ${PREFIX}/etc/users ${PREFIX}/etc/users.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${SED} -e 's,PREFIX,${PREFIX},g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/wzdftpd.sh > ${PREFIX}/etc/rc.d/wzdftpd.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/wzdftpd.sh

.include <bsd.port.mk>
