# Created by: Jeff Brown <jabrown@caida.org>
# $FreeBSD$

PORTNAME=	clisp
PORTVERSION=	2.49.93+
PORTREVISION=	1
CATEGORIES=	lang lisp

MAINTAINER=	kiri@TrueFC.org
COMMENT=	Common Lisp implementation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GNU-GPL

BROKEN_powerpc=	Does not compile
BROKEN_sparc64=	Does not compile

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcall.a:devel/libffcall
LIB_DEPENDS=	libreadline.so:devel/readline \
		libsigsegv.so:devel/libsigsegv

USES=		compiler gettext ghostscript gnome iconv localbase:ldflags
USE_GCC=	any
USE_GITLAB=	yes

GL_ACCOUNT=	gnu-clisp
GL_PROJECT=	clisp
GL_COMMIT=	df3b9f6fdcff22832898e89a989eb499c0f842ed
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1
CONFIGURE_ARGS=	--prefix="${PREFIX}" --mandir="${MANPREFIX}/man" \
		--elispdir="${DATADIR}/emacs" --vimdir="${DATADIR}/vim" \
		--docdir="${DOCSDIR}" --with-libiconv=${ICONV_PREFIX}
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}
# Complaints if the environment changes between build stages.
LDFLAGS+=	${LDFLAGS_${CHOSEN_COMPILER_TYPE}}
LDFLAGS_gcc=	-lthr
MAKE_ENV=	${CONFIGURE_ENV}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	ASDF BDB CLX_MIT CLX_NEW DBUS FASTCGI GDBM GLIBC GTK2 \
		JITC MATLAB NETICA ORACLE PARI PCRE PGSQL QUEENS RAWSOCK \
		SVM THREADS ZLIB
ASDF_DESC=	Another System Definition Facility
BDB_DESC=	Interface to Berkeley DB from Sleepycat Software
CLX_MIT_DESC=	Classical X11 Interface
CLX_NEW_DESC=	Faster X11 Interface (replaces clx/mit-clx)
DBUS_DESC=	Interface to the D-Bus message bus system
FASTCGI_DESC=	FastCGI interface for web development
GDBM_DESC=	Interface to GNU DBM
GLIBC_DESC=	Interface to most of the GNU libc library
GTK2_DESC=	Interface to the GTK library using glade
JITC_DESC=	Use a given Just-In-Time Compiler
SVM_DESC=	Support Vector Machine predictive analytics
MATLAB_DESC=	Matrix calculations using Matlab
NETICA_DESC=	Bayesian belief networks and influence diagrams
ORACLE_DESC=	Oracle RDMBS interface
PARI_DESC=	PARI Computer Algebra System
PCRE_DESC=	Perl-compatible regular expressions
PGSQL_DESC=	PostGreSQL RDMBS interface
QUEENS_DESC=	The Queens Function (a toy example)
RAWSOCK_DESC=	Low level socket interface
THREADS_DESC=	Multithreaded Support (Experimental)
ZLIB_DESC=	Compress vectors

OPTIONS_RADIO=	CLX
OPTIONS_RADIO_CLX=	CLX_MIT CLX_NEW
CLX_DESC=	X11 Module Selection

OPTIONS_DEFAULT=BDB RAWSOCK ZLIB

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

# Segmentation fault in amd64 when using 'mmap(2)', errno = EINVAL.
.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--disable-mmap
.endif

MODULES=	ASDF BDB CLX_MIT CLX_NEW DBUS FASTCGI GDBM GLIBC GTK2 \
		JITC MATLAB NETICA ORACLE PARI PCRE PGSQL QUEENS RAWSOCK \
		SVM ZLIB

.for mod in ${MODULES}
.   if ${PORT_OPTIONS:M${mod}}
PLIST_SUB+=	${mod}=""
.   else
PLIST_SUB+=	${mod}="@comment "
.   endif
.endfor

.if ${PORT_OPTIONS:MASDF}
CONFIGURE_ARGS+=--with-module=asdf
.endif

.if ${PORT_OPTIONS:MBDB}
USES+=		bdb
CONFIGURE_ARGS+=--with-module=berkeley-db
CPPFLAGS+=	-I${LOCALBASE}/include/db${BDB_VER}
LDFLAGS+=	-L${LOCALBASE}/lib/db${BDB_VER}
.endif

.if ${PORT_OPTIONS:MCLX_MIT} || ${PORT_OPTIONS:MCLX_NEW}
USES+=		xorg
USE_XORG=	x11
.endif
.if ${PORT_OPTIONS:MCLX_MIT}
CONFIGURE_ARGS+=--with-module=clx/mit-clx
.endif
.if ${PORT_OPTIONS:MCLX_NEW}
CONFIGURE_ARGS+=--with-module=clx/new-clx
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-1.so:devel/dbus
CONFIGURE_ARGS+=--with-module=dbus
.endif

.if ${PORT_OPTIONS:MFASTCGI}
LIB_DEPENDS+=	libfcgi.so:www/fcgi
CONFIGURE_ARGS+=--with-module=fastcgi
.endif

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=	libgdbm.so:databases/gdbm
CONFIGURE_ARGS+=--with-module=gdbm
.endif

.if ${PORT_OPTIONS:MGLIBC}
USE_LINUX=	base
CONFIGURE_ARGS+=--with-module=bindings/glibc
.endif

.if ${PORT_OPTIONS:MGTK2}
USES+=		gnome
USE_GNOME=	gtk20 libglade2
CONFIGURE_ARGS+=--with-module=gtk2
.endif

.if ${PORT_OPTIONS:MJITC}
BUILD_DEPENDS+=	${LOCALBASE}/include/lightning.h:devel/lightning
LIB_DEPENDS+=	liblightning.so:devel/lightning
CONFIGURE_ARGS+=--with-jitc=lightning
.endif

.if ${PORT_OPTIONS:MMATLAB}
CONFIGURE_ARGS+=--with-module=matlab
.endif

.if ${PORT_OPTIONS:MNETICA}
CONFIGURE_ARGS+=--with-module=netica
.endif

.if ${PORT_OPTIONS:MORACLE}
CONFIGURE_ARGS+=--with-module=oracle
.endif

.if ${PORT_OPTIONS:MPARI}
LIB_DEPENDS+=	libpari.so:math/pari
CONFIGURE_ARGS+=--with-module=pari
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcre.so:devel/pcre
CONFIGURE_ARGS+=--with-module=pcre
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
CONFIGURE_ARGS+=--with-module=postgresql
.endif

.if ${PORT_OPTIONS:MQUEENS}
CONFIGURE_ARGS+=--with-module=queens
.endif

.if ${PORT_OPTIONS:MRAWSOCK}
CONFIGURE_ARGS+=--with-module=rawsock
.endif

.if ${PORT_OPTIONS:MSVM}
BUILD_DEPENDS+=	${LOCALBASE}/bin/svm-predict:science/libsvm
CONFIGURE_ARGS+=--with-module=libsvm
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--with-threads=POSIX_THREADS \
		LDFLAGS="${PTHREAD_LIBS} ${LDFLAGS}"
PKGNAMESUFFIX=	-threaded
.endif

.if ${PORT_OPTIONS:MZLIB}
CONFIGURE_ARGS+=--with-module=zlib
.endif

post-patch:
.if ${PORT_OPTIONS:MORACLE}
	@${REINPLACE_CMD} -e 's|-ldl||; s|-lpthread|-lcompat ${PTHREAD_LIBS}|' \
		${WRKSRC}/modules/oracle/link.sh.in
.endif

pre-install:
.if ${PORT_OPTIONS:MCLX_MIT}
	${CP} ${WRKSRC}/modules/clx/mit-clx/README.CLISP \
		${WRKSRC}/src/clx/mit-clx/README.CLISP
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
