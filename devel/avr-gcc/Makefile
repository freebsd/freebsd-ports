# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	9.1.0
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX=	avr-

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	FSF GCC for Atmel AVR 8-bit RISC cross-development

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BROKEN_aarch64=		Fails to package: cannot find manpages
BROKEN_mips64=		Fails to configure: cannot compute suffix of object files

BUILD_DEPENDS=	avr-as:devel/binutils@avr \
		avr-ld:devel/binutils@avr
LIB_DEPENDS=	libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libisl.so:devel/isl
RUN_DEPENDS=	avr-as:devel/binutils@avr \
		avr-ld:devel/binutils@avr

USES=		bison compiler:c++11-lang gmake iconv libtool localbase \
		makeinfo perl5 tar:xz

# DIST_VERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.  A PORTVERSION of
# 4.Y.2.s20130808 results in values of 4.Y-20130808, 4.Y.2, and 4Y
# for these three.
DIST_VERSION=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.s([0-9]+)/\1-\2/}
GCC_VERSION=	${PORTVERSION:C/(.+)\.s[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}

USE_PERL5=	build
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	avr-gcc-devel*

USE_CXXSTD=	gnu++03

CONFIGURE_ARGS=	--target=avr --disable-libssp --with-gmp=${LOCALBASE} --enable-languages="c c++" \
		--with-isl=${LOCALBASE}

USE_LDCONFIG=	${PREFIX}/lib/gcci/avr/${SUFFIX}

WITHOUT_CPU_CFLAGS=This is a cross-compiler.

INFO=		cpp gcc gccint cppinternals gccinstall

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/gcc/avr/${PORTVERSION}/liblto_plugin.so.0

.include <bsd.port.post.mk>
