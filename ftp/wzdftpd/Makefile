# New ports collection makefile for:	wzdftpd
# Date created:		2003-10-22
# Whom:			Roman Bogorodskiy
#
# $FreeBSD$
#

PORTNAME=	wzdftpd
PORTVERSION=	0.3.2
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Modular FTP server configurable online using SITE commands

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

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

post-extract:
.if defined(WITH_TCL)
	@${REINPLACE_CMD} -e 's|-ltcl8.4|-ltcl84|g' ${WRKSRC}/configure
.endif

post-install:
	${MV} ${PREFIX}/etc/wzd.cfg ${PREFIX}/etc/wzd.cfg.sample
	${MV} ${PREFIX}/etc/users ${DATADIR}/users.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	${SED} -e 's,PREFIX,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
