# New ports collection makefile for:	courier-authdaemon
# Date created:				19 Dec 2004
# Whom:					Oliver Lehmann
#
# $FreeBSD$
#

PORTNAME=	courier-authlib
PORTVERSION=	0.55
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Authentication library used by courier ports

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	yes
USE_LIBTOOL_VER=15
USE_LIBLTDL=	yes

#
# options available:
#
# WITH_MAILUSER:		The user running authlib
# WITH_MAILGROUP:		The group running authlib
# WITH_SYSLOG_FACILITY:		The syslogfacility to use
#

OPTIONS=	PAM		"Build with PAM support"		on \
		VPOPMAIL	"Build in vpopmail support"		off \
		MYSQL		"Build in mysql support"		off \
		POSTGRESQL	"Build in postgresql support"		off \
		LDAP		"Build in ldap support with openldap"	off \
		GDBM		"Use gdbm files instead of bdb"		off \
		AUTHUSERDB	"Build with authuserdb"			on

VPOPMAILDIR?=	${LOCALBASE}/vpopmail
WITH_MAILUSER?=	daemon
WITH_MAILGROUP?=daemon

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CXXFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LDFLAGS} -L${LOCALBASE}/lib"

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-authshadow \
		--without-authcustom \
		--enable-unicode \
		--enable-ltdl-install=no \
		--with-mailuser=${WITH_MAILUSER} \
		--with-mailgroup=${WITH_MAILGROUP} \
		--with-authdaemonvar=/var/run/authdaemond

PLIST_SUB=	MAILUSER=${WITH_MAILUSER} MAILGROUP=${WITH_MAILGROUP}

.include <bsd.port.pre.mk>

.if defined(WITH_SYSLOG_FACILITY)
CONFIGURE_ARGS+=--with-syslog=${WITH_SYSLOG_FACILITY}
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-db=gdbm
.else
CONFIGURE_ARGS+=--with-db=db
.endif

.if !defined(WITH_VPOPMAIL)
CONFIGURE_ARGS+=--without-authvchkpw
PLIST_SUB+=	VPOPMAILFLAG="@comment "
.else
CONFIGURE_ARGS+=--with-authvchkpw
BUILD_DEPENDS+=	${VPOPMAILDIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
PLIST_SUB+=	VPOPMAILFLAG=""
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-authldap
PLIST_SUB+=	LDAPFLAG=""
.else
CONFIGURE_ARGS+=--without-authldap
PLIST_SUB+=	LDAPFLAG="@comment "
.endif

.if !defined(WITH_MYSQL)
CONFIGURE_ARGS+=--without-authmysql
PLIST_SUB+=	MYSQLFLAG="@comment "
.else
USE_MYSQL=	YES
PLIST_SUB+=	MYSQLFLAG=""
CONFIGURE_ARGS+=--with-authmysql \
		--with-mysql-libs=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql
.endif

.if !defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=--without-authpgsql
PLIST_SUB+=	PGSQLFLAG="@comment "
.else
USE_PGSQL=	YES
PLIST_SUB+=	PGSQLFLAG=""
.endif

.if !defined(WITHOUT_PAM)
CONFIGURE_ARGS+=--with-authpam
PLIST_SUB+=	PAMFLAG=""
.else
CONFIGURE_ARGS+=--without-authpam
PLIST_SUB+=	PAMFLAG="@comment "
.endif

.if defined(WITHOUT_AUTHUSERDB)
CONFIGURE_ARGS+=--without-authuserdb
PLIST_SUB+=     AUTHUSERDBFLAG="@comment "
.else
PLIST_SUB+=     AUTHUSERDBFLAG=""
.endif

RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

MAN1=		courierlogger.1

MAN3=		authlib.3 auth_generic.3 auth_login.3 auth_getuserinfo.3 \
		auth_enumerate.3 auth_passwd.3 auth_getoption.3 auth_sasl.3

MAN8=		makeuserdb.8 userdb.8 userdbpw.8

EXTRA_DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		README.authdebug.html README.authmysql.html \
		README.authmysql.myownquery README.authpostgres.html \
		README.ldap README_authlib.html

post-patch:
	@${REINPLACE_CMD} -e 's|$$VPOPMAILLIBS|& -lcrypt|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%INSTALL_MAN%%|${INSTALL_MAN}|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/liblog/Makefile.in \
		${WRKSRC}/userdb/Makefile.in
	@${REINPLACE_CMD} -e 's|DEFAULTOPTIONS=""|DEFAULTOPTIONS="wbnodsn=1"|' \
		${WRKSRC}/authdaemonrc.in
	@${REINPLACE_CMD} -e 's|conftest.lock|/tmp/courier-authlib.locktest|g' \
		${WRKSRC}/liblock/locktest.c

post-configure:
	@${RM} -f /tmp/courier-authlib.locktest

post-install:
	${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/courier-authdaemond.sh > ${WRKDIR}/courier-authdaemond.sh
	${INSTALL_SCRIPT} ${WRKDIR}/courier-authdaemond.sh ${PREFIX}/etc/rc.d/courier-authdaemond.sh
	cd ${WRKSRC} && ( ${GMAKE} install-configure ; cd - )

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for a in ${EXTRA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
