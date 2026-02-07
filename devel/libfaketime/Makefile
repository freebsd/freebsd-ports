PORTNAME=	libfaketime
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.12
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modifies the system time for a single application
WWW=		https://github.com/wolfcw/libfaketime

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	coreutils>=0:sysutils/coreutils
TEST_DEPENDS=	bash:shells/bash

USES=		gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	wolfcw
USE_GCC=	yes
USE_LDCONFIG=	yes
USE_PERL5=	test

SHEBANG_FILES=	test/functests/common.inc test/testframe.sh

# FAKE_STAT doesn't currently work on FreeBSD
# Add -DFAKE_STAT to FEATS to see why

MAKE_ENV+=	FEATS="-DFAKE_SLEEP -DFAKE_TIMERS -DFAKE_INTERNAL_CALLS" \
		WARNS="-Wall"
TEST_TARGET=	test
TESTING_UNSAFE=	The functests/test_exclude_mono.sh:get_monotonic_time() test hangs

PLIST_FILES=	bin/faketime \
		lib/faketime/libfaketime.so.1 \
		lib/faketime/libfaketimeMT.so.1 \
		share/doc/faketime/NEWS \
		share/doc/faketime/README \
		share/man/man1/faketime.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|-lcompat|-lcompat -lutil|' \
		${WRKSRC}/test/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/faketime \
		${STAGEDIR}${PREFIX}/lib/faketime/*.so.*

.include <bsd.port.mk>
