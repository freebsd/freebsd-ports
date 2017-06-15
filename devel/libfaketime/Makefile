# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfaketime
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6-20160627
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Modifies the system time for a single application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	wolfcw
GH_TAGNAME=	da77808

# FAKE_STAT doesn't currently work on FreeBSD
# Add -DFAKE_STAT to FEATS to see why

MAKE_ENV+=	FEATS="-DFAKE_SLEEP -DFAKE_TIMERS -DFAKE_INTERNAL_CALLS" \
		WARNS="-Wall" \
		MANDIR="/man"

PLIST_FILES=	bin/faketime \
		lib/faketime/libfaketime.so.1 \
		lib/faketime/libfaketimeMT.so.1 \
		share/doc/faketime/NEWS \
		share/doc/faketime/README \
		man/man1/faketime.1.gz

SHEBANG_FILES=	test/testframe.sh \
		test/functests/common.inc

TEST_TARGET=	test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/faketime \
		${STAGEDIR}${PREFIX}/lib/faketime/*.so.*

.include <bsd.port.mk>
