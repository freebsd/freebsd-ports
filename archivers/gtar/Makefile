PORTNAME=	tar
DISTVERSION=	1.35
PORTREVISION=	1
CATEGORIES=	archivers sysutils
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU version of the traditional tape archiver
WWW=		https://www.gnu.org/software/tar/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix cpe iconv:${STATIC_ARGS} localbase tar:xz
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=g
# unbuckle safety belt: FreeBSD/i386 still has 32-bit time_t
CONFIGURE_ARGS+=--disable-year2038
CONFIGURE_ENV=	DEFAULT_RMT_COMMAND=/etc/rmt
# supply result to skip a test that will abort configure if run as root
CONFIGURE_ENV+=	gl_cv_func_mknod_works=yes

INFO=		tar

# 1.35 has too many problems in the testsuite:
# missing .at source files, bashisms, brittle xz tests
#TEST_TARGET=	check

OPTIONS_DEFINE=	NLS STATIC
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime:${STATIC_ARGS}
NLS_CONFIGURE_ENABLE=	nls

STATIC_LDFLAGS=	-static
STATIC_CONFIGURE_ENV=	SHLIBEXT=""

STATIC_VARS=	STATIC_ARGS=build
STATIC_VARS_OFF=	STATIC_ARGS=lib

.include <bsd.port.mk>
