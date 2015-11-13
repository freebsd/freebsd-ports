# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	tar
PORTVERSION=	1.28
PORTREVISION=	2
CATEGORIES=	archivers sysutils
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU version of the traditional tape archiver

LICENSE=	GPLv3

INFO=		tar

USES=		charsetfix cpe iconv:${STATIC_ARGS} makeinfo tar:xz
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g \
		--disable-silent-rules
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	DEFAULT_ARCHIVE=/dev/sa0 \
		DEFAULT_RMT_COMMAND=/etc/rmt
# supply result to skip a test that will abort configure if run as root
CONFIGURE_ENV+=	gl_cv_func_mknod_works=yes

# Tests 161 163 are known to fail because path resolution of ".."
# in a removed directory fails.
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
