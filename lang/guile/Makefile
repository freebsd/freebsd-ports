PORTNAME=	guile
PORTVERSION=	3.0.9
PORTREVISION=	2
CATEGORIES=	lang scheme
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension
WWW=		https://www.gnu.org/software/guile/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

# Currently has linker error in i386. Feel free to add other ARCHS in
# case of failure
NOT_FOR_ARCHS=	i386

LIB_DEPENDS=	libffi.so:devel/libffi \
		libgmp.so:math/gmp \
		libltdl.so:devel/libltdl \
		libunistring.so:devel/libunistring

USES=		charsetfix compiler:c11 cpe gmake iconv libtool \
		makeinfo pathfix pkgconfig readline tar:lz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lto=${WITHOUT_LTO:Dno:U${WITH_LTO:Dyes:Uno}}

#MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	guile1 guile2

INFO=		guile r5rs

PLIST_SUB=	GUILE_VER=${PORTVERSION:R}

OPTIONS_DEFINE=		NLS THREADS
OPTIONS_DEFAULT=	NLS THREADS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

THREADS_LIB_DEPENDS=		libgc-threaded.so:devel/boehm-gc-threaded
THREADS_LIB_DEPENDS_OFF=	libgc.so:devel/boehm-gc
THREADS_CONFIGURE_WITH=		threads

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
EXTRA_PATCHES=	${FILESDIR}/extra-patch-bootstrap_Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-i -e|-i.bak -e|' \
		${WRKSRC}/libguile/Makefile.in
	@${RM} -r ${WRKSRC}/prebuilt/32-bit-big-endian

post-patch-THREADS-on:
	@${REINPLACE_CMD} -e 's|bdw-gc|bdw-gc-threaded|g' ${WRKSRC}/configure

# Currently guile fails to run if libs are stripped. Will need to debug
# the case.
#post-install:
#	@${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.go" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
