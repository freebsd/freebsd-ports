# Created by: Jeff Brown <jabrown@caida.org>
# $FreeBSD$

PORTNAME=	clisp
PORTVERSION=	2.49
PORTREVISION=	5
CATEGORIES=	lang lisp
MASTER_SITES=	GNU/${PORTNAME}/release/${PORTVERSION}

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	A Common Lisp implementation

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall
LIB_DEPENDS=	readline.6:${PORTSDIR}/devel/readline \
		sigsegv.2:${PORTSDIR}/devel/libsigsegv

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GNU-GPL

USE_GCC=	any
USES=		iconv
USE_LDCONFIG=	yes
USE_GHOSTSCRIPT_BUILD=	yes
WANT_GNOME=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --mandir="${MANPREFIX}/man" \
		--elispdir="${DATADIR}/emacs" --vimdir="${DATADIR}/vim" \
		--docdir="${DOCSDIR}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}
# Complaints if the environment changes between build stages.
MAKE_ENV=	${CONFIGURE_ENV}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	BDB DBUS FASTCGI GDBM GTK2 PARI PCRE \
		PGSQL RAWSOCK SVM THREADS WILDCARD ZLIB
CLX_MIT_DESC=	X11 module (original MIT version)
CLX_NEW_DESC=	X11 module (new faster version)
PARI_DESC=	PARI (math and calc lib) module
RAWSOCK_DESC=	Raw Socket Access module
SVM_DESC=	Vector Machines module
THREADS_DESC=	Multithreaded Support (Experimental)
WILDCARD_DESC=	Wildcard matching module

OPTIONS_RADIO=	CLX
OPTIONS_RADIO_CLX=	CLX_MIT CLX_NEW
CLX_DESC=	X11 Module Selection

OPTIONS_DEFAULT=	RAWSOCK WILDCARD ZLIB

MAN1=		clisp.1 clisp-link.1
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

# Semgentation fault in amd64 when using 'mmap(2)', errno = EINVAL.
.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--disable-mmap
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

MODULES=	BDB CLX_NEW CLX_MIT DBUS FASTCGI GDBM GTK2 PARI PCRE PGSQL \
		RAWSOCK SVM WILDCARD ZLIB

.for mod in ${MODULES}
.   if ${PORT_OPTIONS:M${mod}}
PLIST_SUB+=	${mod}=""
.   else
PLIST_SUB+=	${mod}="@comment "
.   endif
.endfor

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	43+
CONFIGURE_ARGS+=--with-module=berkeley-db
CPPFLAGS+=	-I${LOCALBASE}/include/db${BDB_VER}
LDFLAGS+=	-L${LOCALBASE}/lib/db${BDB_VER}
.endif

.if ${PORT_OPTIONS:MCLX_MIT} || ${PORT_OPTIONS:MCLX_NEW}
USE_XORG=	x11
.endif
.if ${PORT_OPTIONS:MCLX_MIT}
CONFIGURE_ARGS+=--with-module=clx/mit-clx
.endif
.if ${PORT_OPTIONS:MCLX_NEW}
CONFIGURE_ARGS+=--with-module=clx/new-clx
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--with-module=dbus
.endif

.if ${PORT_OPTIONS:MFASTCGI}
LIB_DEPENDS+=	fcgi.0:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=--with-module=fastcgi
.endif

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=	gdbm.4:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-module=gdbm
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20 libglade2
CONFIGURE_ARGS+=--with-module=gtk2
.endif

.if ${PORT_OPTIONS:MPARI}
LIB_DEPENDS+=	pari-gmp.2:${PORTSDIR}/math/pari
CONFIGURE_ARGS+=--with-module=pari
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-module=pcre
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-module=postgresql
.endif

.if ${PORT_OPTIONS:MRAWSOCK}
CONFIGURE_ARGS+=--with-module=rawsock
.endif

.if ${PORT_OPTIONS:MSVM}
RUN_DEPENDS+=	svm-predict:${PORTSDIR}/science/libsvm
CONFIGURE_ARGS+=--with-module=libsvm
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--with-threads=POSIX_THREADS \
			LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
PKGNAMESUFFIX=		-threaded
.endif

.if ${PORT_OPTIONS:MWILDCARD}
CONFIGURE_ARGS+=--with-module=wildcard
.endif

.if ${PORT_OPTIONS:MZLIB}
CONFIGURE_ARGS+=--with-module=zlib
.endif

post-patch:
.if ${PORT_OPTIONS:MORACLE}
	@${REINPLACE_CMD} -e 's|-ldl||; s|-lpthread|-lcompat ${PTHREAD_LIBS}|' \
		${WRKSRC}/modules/oracle/link.sh
.endif

pre-install:
.if ${PORT_OPTIONS:MCLX_MIT}
	${CP} ${WRKSRC}/modules/clx/mit-clx/README.CLISP \
		${WRKSRC}/src/clx/mit-clx/README.CLISP
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
