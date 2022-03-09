# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	libfaketime
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.10
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modifies the system time for a single application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	wolfcw
GH_TAGNAME=	da77808
USE_LDCONFIG=	yes

SHEBANG_FILES=	test/functests/common.inc test/testframe.sh

# FAKE_STAT doesn't currently work on FreeBSD
# Add -DFAKE_STAT to FEATS to see why

MAKE_ENV+=	FEATS="-DFAKE_SLEEP -DFAKE_TIMERS -DFAKE_INTERNAL_CALLS" \
		MANDIR="/man" \
		WARNS="-Wall"
TEST_TARGET=	test

PLIST_FILES=	bin/faketime \
		lib/faketime/libfaketime.so.1 \
		lib/faketime/libfaketimeMT.so.1 \
		man/man1/faketime.1.gz \
		share/doc/faketime/NEWS \
		share/doc/faketime/README

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/faketime \
		${STAGEDIR}${PREFIX}/lib/faketime/*.so.*

.include <bsd.port.mk>
