PORTNAME=	gcc
PORTVERSION=	10.2.0
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX=	avr-

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	FSF GCC for Atmel AVR 8-bit RISC cross-development

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BROKEN_mips64=	Fails to configure: cannot compute suffix of object files

BUILD_DEPENDS=	avr-as:devel/binutils@avr \
		avr-ld:devel/binutils@avr \
		objdump:devel/binutils
LIB_DEPENDS=	libgmp.so:math/gmp \
		libisl.so:devel/isl \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	avr-as:devel/binutils@avr \
		avr-ld:devel/binutils@avr

USES=		bison compiler:c++11-lang gmake iconv libtool localbase \
		makeinfo perl5 tar:xz
USE_CXXSTD=	gnu++03
USE_LDCONFIG=	${PREFIX}/lib/gcci/avr/${SUFFIX}
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-libssp \
		--enable-languages="c c++" \
		--target=avr \
		--with-gmp=${LOCALBASE} \
		--with-isl=${LOCALBASE} \
		--without-zstd

PLIST_SUB=	VERSION=${GCC_VERSION}

WITHOUT_CPU_CFLAGS=	This is a cross-compiler.

CONFLICTS=	avr-gcc-devel*

INFO=		cpp gcc gccint cppinternals gccinstall

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

# DIST_VERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.  A PORTVERSION of
# 4.Y.2.s20130808 results in values of 4.Y-20130808, 4.Y.2, and 4Y
# for these three.
DIST_VERSION=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.s([0-9]+)/\1-\2/}
GCC_VERSION=	${PORTVERSION:C/(.+)\.s[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name '*.[ch]' -o -name '*.cc' \) | \
		${XARGS} ${EGREP} -l '"(HOST_WIDE|PLUGIN_COND|PRId64)' | \
		${XARGS} ${REINPLACE_CMD} -E -e 's/"(HOST_WIDE|PLUGIN_COND|PRId64)/" \1/g'

post-configure:
	${MKDIR} ${WRKSRC}/gcc/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/gcc/avr/${PORTVERSION}/liblto_plugin.so.0 \
		${STAGEDIR}${PREFIX}/lib/libcc1.so.0.0.0 \
		${STAGEDIR}${PREFIX}/lib/gcc/avr/${PORTVERSION}/plugin/libcc1plugin.so.0.0.0 \
		${STAGEDIR}${PREFIX}/lib/gcc/avr/${PORTVERSION}/plugin/libcp1plugin.so.0.0.0

.include <bsd.port.post.mk>
