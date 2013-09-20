# Created by: ijliao
# $FreeBSD$

PORTNAME=	libmba
PORTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://www.ioplex.com/~miallen/libmba/dl/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of C modules potentially useful to any project

MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
USE_LDCONFIG=	yes

MAN3=		allocator.3m bitset.3m cfg.3m csv.3m diff.3m eval.3m hashmap.3m \
		hexdump.3m linkedlist.3m msgno.3m path.3m pool.3m shellout.3m \
		stack.3m suba.3m svcond.3m svsem.3m text.3m time.3m varray.3m
MANCOMPRESSED=	yes

SHLIB_MAJOR=	0

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,-g,$$(CFLAGS),' \
		-e '/^prefix/s/=/?=/' \
		-e 's/prefix/PREFIX/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -Ee 's,"g?cc","${CC}",' \
		${WRKSRC}/mktool.c

.include <bsd.port.mk>
