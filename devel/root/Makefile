# New ports collection makefile for:   root
# Date created:        17 July 2004
# Whom:                Simon Lang <simon@lang-clan.de>
#
# $FreeBSD$
#

PORTNAME=		root
PORTVERSION=		4.02.00
CATEGORIES=		devel science math
MASTER_SITES=		ftp://root.cern.ch/root/
DISTNAME=		${PORTNAME}_v${PORTVERSION}.source

MAINTAINER=		simon@lang-clan.de
COMMENT=		An Object-Oriented Data Analysis Framework

HAS_CONFIGURE=		yes
CONFIGURE_TARGET=	freebsd5
ALL_TARGET=		showbuild skip all
MAKE_FLAGS=		ARCH=freebsd5
### something more needed for OpenSSL ???
USE_OPENSSL=		yes
USE_GMAKE=		yes
USE_XLIB=		yes
USE_XPM=		yes
USE_GL=			yes
USE_REINPLACE=		yes
LIB_DEPENDS=		gmp.6:${PORTSDIR}/math/libgmp4
USE_GNOME=		libxml2
REINPLACE_ARGS=		-i ""
WRKSRC=			${WRKDIR}/${PORTNAME}

F77?=			f77

# If you have installed MySQL (ports/databases/mysql50-client), then
# you may enable ROOT's support for it, too.
# A known but yet unsolved problem: The support of Kerberos 5 needs some
# patches to ROOT.
# A lot of the features are related to software used in high
# energy physics projects. Have a look to the ROOT web page for more
# informations.
CONFIGURE_ARGS=		${CONFIGURE_TARGET}		\
			--prefix=${PREFIX}		\
			--etcdir=${PREFIX}/etc		\
			--mandir=${PREFIX}/man/man1	\
			--disable-afs			\
			--disable-alien			\
			--disable-cern			\
			--disable-chirp			\
			--disable-dcache		\
			--disable-globus		\
			--disable-krb5			\
			--disable-mysql			\
			--disable-python		\
			--disable-pythia		\
			--disable-pythia6		\
			--disable-rfio			\
			--disable-rpath			\
			--disable-ruby			\
			--disable-sapdb			\
			--disable-shadowpw		\
			--disable-venus			\
			--disable-xrootd		\
			--enable-exceptions		\
			--enable-explicitlink		\
			--enable-opengl			\
			--enable-shared			\
			--enable-soversion		\
			--enable-ssl			\
			--enable-table			\
			--enable-xml

INSTALLS_SHLIB=		yes
NO_FILTER_SHLIBS=	yes
LDCONFIG_DIRS=		%%PREFIX%%/lib/root %%PREFIX%%/lib/root/cint
MAN1=			cint.1 g2root.1 h2root.1 hadd.1 makecint.1 memprobe.1
MAN1+=			proofd.1 proofserv.1 rmkdepend.1 root-config.1 root.1
MAN1+=			root.exe.1 rootcint.1 rootd.1 rootn.exe.1
MAN1+=			system.rootdaemonrc.1

MODTESTS=		Event hsimple minexam tcollex tstring
MAKE_TENV=		${MAKE_ENV} CXX="${CXX}" LDFLAGS="${LDFLAGS}"

# Auto detection of installed packages which then can be used by ROOT
.if exists(${LOCALBASE}/lib/libpq.so.3)
WITH_POSTGRESQL=	yes
.endif

.if exists(${LOCALBASE}/lib/libldap.so.2)
WITH_LDAP=		yes
.endif

.if exists(${LOCALBASE}/lib/libsrp.a)
WITH_SRP=		yes
.endif

# Settings depending on additionally installed packages
.if !defined(WITHOUT_QT)
USE_QT_VER=		3
QT_NONSTANDARD=		yes
CONFIGURE_ARGS+=	--enable-qt                           \
			--with-qt-incdir=${QT_PREFIX}/include \
			--with-qt-libdir=${QT_PREFIX}/lib
PLIST_SUB+=		QT=""
.else
CONFIGURE_ARGS+=	--disable-qt
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff      \
			jpeg.9:${PORTSDIR}/graphics/jpeg      \
			png.5:${PORTSDIR}/graphics/png        \
			ungif.5:${PORTSDIR}/graphics/libungif
PLIST_SUB+=		QT="@comment "
.endif

.if !defined(WITHOUT_AFTERIMAGE)
CONFIGURE_ARGS+=	--enable-asimage
PLIST_SUB+=		AFTERIMAGE=""
LIB_DEPENDS+=		AfterImage.0:${PORTSDIR}/graphics/libafterimage
.else
CONFIGURE_ARGS+=	--disable-asimage
PLIST_SUB+=		AFTERIMAGE="@comment "
.endif

.if !defined(WITHOUT_POSTGRESQL) && defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	--enable-pgsql
USE_PGSQL=		yes
PLIST_SUB+=		POSTGRESQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=		POSTGRESQL="@comment "
.endif

.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap
PLIST_SUB+=		LDAP=""
.else
CONFIGURE_ARGS+=	--disable-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

.if !defined(WITHOUT_SRP) && defined(WITH_SRP)
CONFIGURE_ARGS+=	--enable-srp
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsrp.a:${PORTSDIR}/security/srp
.else
CONFIGURE_ARGS+=	--disable-srp
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=			Does not compile
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=			Does not compile
.endif

# The thread sub-system was not working for ROOT versions 3.x on FreeBSD 4.x
# systems. Meanwhile maybe it's working with some patches - but I have no
# FreeBSD 4.x system still running for testing  ;-)
.if ${OSVERSION} < 500016 || defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--disable-thread
PLIST_SUB+=		THREADS="@comment "
.else
CONFIGURE_ARGS+=	--enable-thread
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
			PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
			PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB+=		THREADS=""
.endif

pre-everything::
.if !defined(WITHOUT_QT)
	@${ECHO_MSG} "===> Define WITHOUT_QT to disable QT backend"
.endif
.if !defined(WITHOUT_THREADS)
	@${ECHO_MSG} "===> Define WITHOUT_THREADS to disable threads"
.endif
.if !defined(WITHOUT_AFTERIMAGE)
	@${ECHO_MSG} "===> Define WITHOUT_AFTERIMAGE to disable AfterImage support"
.endif
.if defined(WITHOUT_LDAP) || !defined(WITH_LDAP)
	@${ECHO_MSG} "===> Define WITH_LDAP to enable LDAP support"
.endif
.if defined(WITHOUT_SRP) || !defined(WITH_SRP)
	@${ECHO_MSG} "===> Define WITH_SRP to enable SRP authentification"
.endif
.if defined(WITHOUT_POSTGRESQL) || !defined(WITH_POSTGRESQL)
	@${ECHO_MSG} "===> Define WITH_POSTGRESQL to enable Postgres SQL support"
.endif
	@sleep 3

post-patch:
#	@${RM} ${WRKSRC}/configure.orig
#	@${RM} ${WRKSRC}/config/Makefile.freebsd4.orig
#	@${RM} ${WRKSRC}/config/Makefile.freebsd5.orig
	@${RM} ${WRKSRC}/config/root-config.in.orig
	@${RM} ${WRKSRC}/test/Makefile.arch.orig
	@${RM} ${WRKSRC}/xml/Module.mk.orig
.if ${OSVERSION} < 500016 || defined(WITHOUT_THREADS)
	@${REINPLACE_CMD} -e                                  \
		's|auxcflags=\"PTHREAD-CFLAGS|auxcflags=\"| ; \
		s|auxlibs=\"PTHREAD-LIBS|auxlibs=\"|'         \
		${WRKSRC}/config/root-config.in
.else
	@${REINPLACE_CMD} -e                                                 \
		's|auxcflags=\"PTHREAD-CFLAGS|auxcflags=\"${PTHREAD_CFLAGS}|;\
		s|auxlibs=\"PTHREAD-LIBS|auxlibs=\"${PTHREAD_LIBS}|'         \
		${WRKSRC}/config/root-config.in
.endif

.if defined(MAINTAINER_MODE)
test:	install
	(cd ${DOCSDIR}/test ;	\
	${SETENV} ${MAKE_TENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})
. for module in ${MODTESTS}
	(cd ${DOCSDIR}/test ;	\
	${SETENV} LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH} ./${module})
. endfor
.endif

.include <bsd.port.post.mk>
