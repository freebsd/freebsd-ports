PORTNAME=	clisp
PORTVERSION=	2.49.95+20241228
PORTREVISION=	2
CATEGORIES=	lang lisp

MAINTAINER=	kiri@TrueFC.org
COMMENT=	Common Lisp implementation
WWW=		https://www.gnu.org/software/clisp/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GNU-GPL

LIB_DEPENDS=	libffcall.so:devel/libffcall \
		libreadline.so:devel/readline \
		libsigsegv.so:devel/libsigsegv \
		libunistring.so:devel/libunistring
RUN_DEPENDS=	cl-freebsd-asdf-init>=0:devel/cl-freebsd-asdf-init

USES=		gettext ghostscript iconv localbase:ldflags ncurses \
		pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	gnu-clisp
GL_PROJECT=	clisp
GL_TAGNAME=	c3ec11bab87cfdbeba01523ed88ac2a16b22304d

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--docdir="${DOCSDIR}" \
			--elispdir="${DATADIR}/emacs" \
			--mandir="${PREFIX}/share/man" \
			--prefix="${PREFIX}" \
			--vimdir="${DATADIR}/vim" \
			--with-libiconv=${ICONV_PREFIX}
CONFIGURE_ENV=		FORCE_UNSAFE_CONFIGURE=1
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}

MAKE_ENV=		${CONFIGURE_ENV}
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=		ASDF BDB DBUS DOCS FASTCGI GDBM GTK2 NLS PARI PCRE \
			PGSQL QUEENS RAWSOCK SVM ZLIB
OPTIONS_DEFAULT=	ASDF BDB RAWSOCK ZLIB
OPTIONS_RADIO=		CLX
OPTIONS_RADIO_CLX=	CLX_MIT CLX_NEW
OPTIONS_SUB=		YES

ASDF_DESC=	Another System Definition Facility
BDB_DESC=	Interface to Berkeley DB from Sleepycat Software
CLX_DESC=	X11 Module Selection
CLX_MIT_DESC=	Classical X11 Interface
CLX_NEW_DESC=	Faster X11 Interface (replaces clx/mit-clx)
DBUS_DESC=	Interface to the D-Bus message bus system
FASTCGI_DESC=	FastCGI interface for web development
GDBM_DESC=	Interface to GNU DBM
GTK2_DESC=	Interface to the GTK library using glade
PARI_DESC=	PARI Computer Algebra System
PCRE_DESC=	Perl-compatible regular expressions
PGSQL_DESC=	PostGreSQL RDMBS interface
QUEENS_DESC=	The Queens Function (a toy example)
RAWSOCK_DESC=	Low level socket interface
SVM_DESC=	Support Vector Machine predictive analytics
ZLIB_DESC=	Compress vectors

ASDF_CONFIGURE_WITH=	module=asdf
BDB_USES=		bdb
BDB_CONFIGURE_WITH=	module=berkeley-db
BDB_CPPFLAGS=		-I${LOCALBASE}/include/db${BDB_VER}
BDB_LDFLAGS=		-L${LOCALBASE}/lib/db${BDB_VER}
CLX_MIT_USES=		xorg
CLX_MIT_USE=		XORG=x11
CLX_MIT_CONFIGURE_WITH=	module=clx/mit-clx
CLX_NEW_USES=		xorg
CLX_NEW_USE=		XORG=x11
CLX_NEW_CONFIGURE_WITH=	module=clx/new-clx
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_WITH=	module=dbus
FASTCGI_LIB_DEPENDS=	libfcgi.so:www/fcgi
FASTCGI_CONFIGURE_WITH=	module=fastcgi
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	module=gdbm
GTK2_USES=		gnome
GTK2_USE=		GNOME=gtk20,libglade2
GTK2_CONFIGURE_WITH=	module=gtk2
PARI_LIB_DEPENDS=	libpari.so:math/pari
PARI_CONFIGURE_WITH=	module=pari
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	module=pcre
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	module=postgresql
QUEENS_CONFIGURE_WITH=	module=queens
RAWSOCK_CONFIGURE_WITH=	module=rawsock
SVM_LIB_DEPENDS=	libsvm.so.2:science/libsvm
SVM_CONFIGURE_WITH=	module=libsvm
ZLIB_CONFIGURE_WITH=	module=zlib

pre-install-CLX_MIT-on:
	${CP} ${WRKSRC}/modules/clx/mit-clx/README.CLISP \
		${WRKSRC}/src/clx/mit-clx/README.CLISP

post-install:
	${STRIP_CMD} $$(${FIND} ${STAGEDIR}${PREFIX}/lib/clisp/dynmod/*.so) \
	${STAGEDIR}${PREFIX}/bin/clisp

do-test:
	@cd ${WRKSRC}/tests && \
		${LOCALBASE}/bin/clisp -E UTF-8 -i "tests" -x "(run-all-tests)"

.include <bsd.port.options.mk>

# Segmentation fault in amd64 when using 'mmap(2)', errno = EINVAL.
.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--disable-mmap
.endif

.include <bsd.port.mk>
