PORTNAME=	libtool
PORTREVISION=	1

COMMENT=	Generic shared library support script
WWW=		https://www.gnu.org/software/libtool/

.include "${.CURDIR}/../libtool/Makefile.common"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm4:devel/m4
RUN_DEPENDS=	gm4:devel/m4

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-ltdl-install
TEST_TARGET=	check

NO_ARCH=	yes
INFO=		libtool

.if "${CC}" == "/nxb-bin/usr/bin/cc"
# Generate libtool script for the native compiler, not the cross compiler.
CC=		cc
CXX=		c++
LD=		ld
.endif

# Perform the patching after the build, because touching m4 files before the
# configuration step causes autoreconf to be invoked
post-stage:
	cd ${STAGEDIR}${PREFIX}/share/aclocal && \
		${PATCH} --posix -p1 < ${PATCHDIR}/stagepatch-m4_libtool.m4

.include <bsd.port.mk>
