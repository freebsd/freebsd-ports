# New ports collection makefile for:    clisp
# Date created:         Feb  5 2000
# Whom:                 Jeff Brown <jabrown@caida.org>
#
# $FreeBSD$
#

PORTNAME=	clisp
PORTVERSION=	2.48
PORTREVISION=	4
CATEGORIES=	lang lisp
MASTER_SITES=	GNU/${PORTNAME}/release/${PORTVERSION}

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	A Common Lisp implementation

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall
LIB_DEPENDS=	readline.6:${PORTSDIR}/devel/readline \
		sigsegv.2:${PORTSDIR}/devel/libsigsegv

USE_ICONV=	yes
USE_GHOSTSCRIPT_BUILD=	yes
WANT_GNOME=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --mandir="${MANPREFIX}/man" \
		--elispdir="${DATADIR}/emacs" --vimdir="${DATADIR}/vim" \
		--docdir="${DOCSDIR}"
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}
# Complaints if the environment changes between build stages.
MAKE_ENV=	${CONFIGURE_ENV}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=yes

OPTIONS=	BDB "Build Berkeley Database module" off \
		CLX_MIT "Build X11 module (original MIT version)" off \
		CLX_NEW "Build X11 module (new faster version)" off \
		DBUS "D-BUS control module" Off \
		FASTCGI "Build FastCGI module" off \
		GDBM "Build GNU Database manager module" off \
		GTK2 "Build Gtk+2 module" off \
		ORACLE "Build Oracle database module" off \
		PARI "Build PARI (math and calc lib) module" off \
		PCRE "Build PCRE (Perl Compatible Regexp) module" off \
		PGSQL "Build PostgreSQL database module" off \
		RAWSOCK "Build Raw Socket Access module" on \
		SVM "Enable Support Vector Machines module" off \
		THREADS "Enable multithreaded (Experimental)" Off \
		WILDCARD "Build wildcard matching module" on \
		ZLIB "Build ZLib interface module " off

MAN1=		clisp.1
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

# Semgentation fault in amd64 when using 'mmap(2)', errno = EINVAL.
.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--disable-mmap
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

MODULES=	BDB CLX_MIT CLX_NEW DBUS FASTCGI GDBM GTK2 ORACLE PARI PCRE \
		PGSQL RAWSOCK SVM WILDCARD ZLIB

.for mod in ${MODULES}
.   if defined(WITH_${mod})
PLIST_SUB+=	${mod}=""
.   else
PLIST_SUB+=	${mod}="@comment "
.   endif
.endfor

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if defined(WITH_BDB)
USE_BDB=	43+
CONFIGURE_ARGS+=--with-module=berkeley-db
CPPFLAGS+=	-I${LOCALBASE}/include/db${BDB_VER}
LDFLAGS+=	-L${LOCALBASE}/lib/db${BDB_VER}
.endif

.if defined(WITH_CLX_MIT) && defined(WITH_CLX_NEW)
IGNORE=		selected different implementations of the same X11 module
.endif
.if defined(WITH_CLX_MIT) || defined(WITH_CLX_NEW)
USE_XORG=	x11
.endif
.if defined(WITH_CLX_MIT)
CONFIGURE_ARGS+=--with-module=clx/mit-clx
.endif
.if defined(WITH_CLX_NEW)
CONFIGURE_ARGS+=--with-module=clx/new-clx
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=   dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--with-module=dbus
.endif

.if defined(WITH_FASTCGI)
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=--with-module=fastcgi
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-module=gdbm
.endif

.if defined(WITH_GTK2)
USE_GNOME=	gtk20 libglade2
CONFIGURE_ARGS+=--with-module=gtk2
.endif

.if defined(WITH_ORACLE)
BUILD_DEPENDS+=	${ORACLE_HOME}:${PORTSDIR}/databases/oracle8-client
CONFIGURE_ARGS+=--with-module=oracle
CPPFLAGS+=	-I${ORACLE_HOME}/rdbms/demo -I${ORACLE_HOME}/rdbms/public
LDFLAGS+=	-L${ORACLE_HOME}/lib
ORACLE_HOME?=	${LOCALBASE}/oracle8-client
.endif

.if defined(WITH_PARI)
LIB_DEPENDS+=	pari-gmp.2:${PORTSDIR}/math/pari
CONFIGURE_ARGS+=--with-module=pari
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-module=pcre
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-module=postgresql
.endif

.if defined(WITH_RAWSOCK)
CONFIGURE_ARGS+=--with-module=rawsock
.endif

.if defined(WITH_SVM)
RUN_DEPENDS+=	svm-predict:${PORTSDIR}/science/libsvm
CONFIGURE_ARGS+=--with-module=libsvm
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--with-threads=POSIX_THREADS \
			LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
PKGNAMESUFFIX=		-threaded
.endif

.if defined(WITH_WILDCARD)
CONFIGURE_ARGS+=--with-module=wildcard
.endif

.if defined(WITH_ZLIB)
CONFIGURE_ARGS+=--with-module=zlib
.endif

post-patch:
.if defined(WITH_ORACLE)
	@${REINPLACE_CMD} -e 's|-ldl||; s|-lpthread|-lcompat ${PTHREAD_LIBS}|' \
		${WRKSRC}/modules/oracle/link.sh
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
