# New ports collection makefile for:   root
# Date created:        17 July 2004
# Whom:                Simon Lang <simon@lang-clan.de>
#
# $FreeBSD$
#

PORTNAME=		root
PORTVERSION=		5.02.00
CATEGORIES=		devel science math
MASTER_SITES=		ftp://root.cern.ch/root/
DISTNAME=		${PORTNAME}_v${PORTVERSION}.source

MAINTAINER=		simon@lang-clan.de
COMMENT=		An Object-Oriented Data Analysis Framework

HAS_CONFIGURE=		yes
CONFIGURE_TARGET=	freebsd5
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
			PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=		showbuild skip all
MAKE_FLAGS=		ARCH=freebsd5
MAKE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
			PTHREAD_LIBS="${PTHREAD_LIBS}"

REINPLACE_ARGS=		-i ""
WRKSRC=			${WRKDIR}/${PORTNAME}

F77?=			f77

LIB_DEPENDS=		freetype.9:${PORTSDIR}/print/freetype2
LIB_DEPENDS+=		jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
LIB_DEPENDS+=		gmp.6:${PORTSDIR}/math/libgmp4
USE_OPENSSL=		yes
USE_GMAKE=		yes
USE_XLIB=		yes
USE_XPM=		yes
USE_GL=			yes
USE_GNOME=		libxml2

# A lot of additional features are most likely used in high energy physics
# projects. Have a look to the ROOT web page for more informations on those
# software packages.
# 'cintex', 'mathmore' and 'reflex' are disabled due to a lot of bugs in this
# version of Root. However in the CVS head they were already fixed by the time
# this port was written.
CONFIGURE_ARGS=		${CONFIGURE_TARGET}		\
			--prefix=${PREFIX}		\
			--etcdir=${PREFIX}/etc		\
			--mandir=${PREFIX}/man/man1	\
			--disable-afs			\
			--disable-alien			\
			--disable-builtin-freetype	\
			--disable-cern			\
			--disable-chirp			\
			--disable-cintex		\
			--disable-clarens		\
			--disable-dcache		\
			--disable-globus		\
			--disable-mathmore		\
			--disable-oracle		\
			--disable-peac			\
			--disable-pythia		\
			--disable-pythia6		\
			--disable-reflex		\
			--disable-rfio			\
			--disable-sapdb			\
			--disable-shadowpw		\
			--disable-venus			\
			--enable-exceptions		\
			--enable-explicitlink		\
			--enable-mathcore		\
			--enable-opengl			\
			--enable-roofit			\
			--enable-rpath			\
			--enable-shared			\
			--enable-soversion		\
			--enable-ssl			\
			--enable-table			\
			--enable-thread			\
			--enable-xml			\
			--enable-xrootd

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes
LDCONFIG_DIRS=		%%PREFIX%%/lib/root %%PREFIX%%/lib/root/cint
MAN1=			cint.1 g2root.1 g2rootold.1 h2root.1 hadd.1 makecint.1
MAN1+=			memprobe.1 olbd.1 proofd.1 proofserv.1 rlibmap.1
MAN1+=			rmkdepend.1 root-config.1 root.1 root.exe.1 rootcint.1
MAN1+=			rootd.1 rootn.exe.1 ssh2rpd.1 system.rootdaemonrc.1
MAN1+=			xrootd.1
USE_RC_SUBR=		rootlibs.sh

MODTESTS=		Event hsimple minexam tcollex tcollbm tstring
MAKE_TENV=		${MAKE_ENV} CXX="${CXX}" LDFLAGS="${LDFLAGS}"

### Additional features used by default

.if !defined(WITHOUT_QT)
USE_QT_VER=		3
QT_NONSTANDARD=		yes
CONFIGURE_ARGS+=	--enable-qt                           \
			--with-qt-incdir=${QT_PREFIX}/include \
			--with-qt-libdir=${QT_PREFIX}/lib
PLIST_SUB+=		QT=""
.else
CONFIGURE_ARGS+=	--disable-qt
PLIST_SUB+=		QT="@comment "
.endif

.if !defined(WITHOUT_AFTERIMAGE)
CONFIGURE_ARGS+=	--enable-asimage		\
			--enable-builtin-afterimage
PLIST_SUB+=		AFTERIMAGE=""
.else
CONFIGURE_ARGS+=	--disable-asimage		\
			--disable-builtin-afterimage
PLIST_SUB+=		AFTERIMAGE="@comment "
.endif

### Auto detection of additional features not used by default

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libkrb5.so.3)
WITH_KRB5=		yes
.endif

.if exists(${LOCALBASE}/lib/libldap-2.2.so)
WITH_LDAP=		yes
.endif

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.12)
WITH_MYSQL=		yes
.endif

.if exists(${LOCALBASE}/lib/libpq.so.3)
WITH_POSTGRESQL=	yes
.endif

.if exists(${LOCALBASE}/lib/libpython2.4.so.1)
WITH_PYTHON=		yes
.endif

.if exists(${LOCALBASE}/lib/libruby18.so.18)
WITH_RUBY=		yes
.endif

.if exists(${LOCALBASE}/lib/libsrp.a)
WITH_SRP=		yes
.endif

### Additional features not used by default

.if !defined(WITHOUT_KRB5) && defined(WITH_KRB5)
LIB_DEPENDS+=		krb5.3:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--enable-krb5				\
			--with-krb5-incdir=${LOCALBASE}/include	\
			--with-krb5-libdir=${LOCALBASE}/lib
PLIST_SUB+=		KRB5=""
.else
CONFIGURE_ARGS+=	--disable-krb5
PLIST_SUB+=		KRB5="@comment "
.endif

.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
PLIST_SUB+=		LDAP=""
.else
CONFIGURE_ARGS+=	--disable-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

.if !defined(WITHOUT_MYSQL) && defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=		yes
PLIST_SUB+=		MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if !defined(WITHOUT_POSTGRESQL) && defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--enable-pgsql
USE_PGSQL=		yes
PLIST_SUB+=		POSTGRESQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=		POSTGRESQL="@comment "
.endif

.if !defined(WITHOUT_PYTHON) && defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--enable-python
USE_PYTHON=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.if !defined(WITHOUT_RUBY) && defined(WITH_RUBY)
CONFIGURE_ARGS+=	--enable-ruby
USE_RUBY=		yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
PLIST_SUB+=		RUBY=""
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=		RUBY="@comment "
.endif

.if !defined(WITHOUT_SRP) && defined(WITH_SRP)
CONFIGURE_ARGS+=	--enable-srp
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsrp.a:${PORTSDIR}/security/srp
.else
CONFIGURE_ARGS+=	--disable-srp
.endif

### Rules and version dependend variables

.if ${OSVERSION} < 500016
BROKEN=			"Does not compile / Needs thread support"
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=			"Does not compile"
.endif

pre-everything::
	@${ECHO_MSG} \
		"===> Use WITH_? or WITHOUT_? to (de-)activate build options,"
	@${ECHO_MSG} "     where ? stands for:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "       AFTERIMAGE - use Root's internal version"
	@${ECHO_MSG} "       KRB5       - support Kerberos V authentification"
	@${ECHO_MSG} "       LDAP       - LDAP support"
	@${ECHO_MSG} "       MYSQL      - MySQL database support"
	@${ECHO_MSG} "       POSTGRESQL - Postgesql database support"
	@${ECHO_MSG} "       PYTHON     - Python bindings"
	@${ECHO_MSG} "       QT         - QT backend"
	@${ECHO_MSG} "       RUBY       - Ruby bindings"
	@${ECHO_MSG} "       SRP        - support SRP authentification"
	@${ECHO_MSG} ""
	@sleep 5

post-patch:
	@${RM} ${WRKSRC}/config/root-config.in.orig
	@${RM} ${WRKSRC}/test/Makefile.arch.orig
	@${RM} ${WRKSRC}/cint/lib/pthread/setup.orig
	@${RM} ${WRKSRC}/base/src/TMath.cxx.orig
	@${RM} ${WRKSRC}/configure.orig
	@${RM} ${WRKSRC}/x11ttf/Module.mk.orig
	@${REINPLACE_CMD} -e                                                 \
		's|auxcflags=\"PTHREAD-CFLAGS|auxcflags=\"${PTHREAD_CFLAGS}|;\
		s|auxlibs=\"PTHREAD-LIBS|auxlibs=\"${PTHREAD_LIBS}|'         \
		${WRKSRC}/config/root-config.in

.if defined(MAINTAINER_MODE)
test:	install
	(cd ${DOCSDIR}/test ;	\
	${SETENV} ${MAKE_TENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
. for module in ${MODTESTS}
	(cd ${DOCSDIR}/test ;	\
	${SETENV} LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH}:./${module})
. endfor
.endif

.include <bsd.port.post.mk>
