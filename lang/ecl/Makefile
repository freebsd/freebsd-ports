PORTNAME=	ecl
PORTVERSION=	24.5.10
CATEGORIES=	lang lisp
MASTER_SITES=	https://common-lisp.net/project/ecl/static/files/release/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ANSI Common Lisp implementation
WWW=		https://common-lisp.net/project/ecl/main.html

LICENSE=	LGPL20

BROKEN_mips=	fails to build: qemu: uncaught target signal 11 (Segmentation fault) - core dumped
BROKEN_mips64=	fails to build: qemu: uncaught target signal 11 (Segmentation fault) - core dumped

BUILD_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops
LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libgmp.so:math/gmp
RUN_DEPENDS=	${LOCALBASE}/lib/libatomic_ops.a:devel/libatomic_ops

USES=		autoreconf gmake localbase makeinfo perl5 tar:tgz
USE_LDCONFIG=	yes
USE_PERL5=	build
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-boehm=system \
		--enable-libatomic=system \
		--with-gmp-prefix=${LOCALBASE} \
		--with-system-gmp

MAKE_JOBS_UNSAFE=	yes

AUTORECONF_WRKSRC=	${WRKSRC}/src
INFO=			ecl
PLIST_SUB=		VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		ASDF CXX DFFI SAGE SOCKETS THREADS X11
OPTIONS_DEFAULT=	ASDF DFFI SAGE SOCKETS THREADS
OPTIONS_SUB=		yes

ASDF_DESC=	Enable ASDF building facility
CXX_DESC=	Enable C++ support
DFFI_DESC=	Dynamic foreign-function support
SAGE_DESC=	Build with patches for sage
SOCKETS_DESC=	Enable socket interface

ASDF_CONFIGURE_ON=	--with-asdf=yes
ASDF_CONFIGURE_OFF=	--with-asdf=no
CXX_CONFIGURE_ON=	--with-cxx
CXX_VARS_OFF=		USE_CSTD=c99
DFFI_LIB_DEPENDS=	libffi.so:devel/libffi
DFFI_CONFIGURE_ON=	--with-dffi=system
DFFI_CONFIGURE_OFF=	--with-dffi=no
SAGE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_aclocal.m4 \
			${PATCHDIR}/extra-patch-src_c_file.d \
			${PATCHDIR}/extra-patch-src_compile.lsp.in \
			${PATCHDIR}/extra-patch-src_configure.ac \
			${PATCHDIR}/extra-patch-src_Makefile.in
SOCKETS_CONFIGURE_ON=	--with-tcp=yes
SOCKETS_CONFIGURE_OFF=	--with-tcp=no
THREADS_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
THREADS_CONFIGURE_ON=	--enable-threads=yes
THREADS_CONFIGURE_OFF=	--enable-threads=no
THREADS_LDFLAGS=	-lpthread -lgc-threaded
X11_USES=		xorg
X11_USE=		XORG=x11
X11_CONFIGURE_ON=	--with-x=yes
X11_CONFIGURE_OFF=	--with-x=no

post-patch-THREADS-on:
	@${REINPLACE_CMD} -e 's|-lgc|-lgc-threaded|' ${WRKSRC}/src/configure

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/include/ecl/gc/private
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libecl.so.${PORTVERSION}
	${LN} -sf ecl-${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/ecl

.include <bsd.port.mk>
