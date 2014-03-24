# Created by: ijliao
# $FreeBSD$

PORTNAME=	libmba
PORTVERSION=	0.9.1
CATEGORIES=	devel
MASTER_SITES=	http://www.ioplex.com/~miallen/libmba/dl/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of C modules potentially useful to any project

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's,-g,$$(CFLAGS),' \
		-e '/^prefix/s/=/?=/' \
		-e 's/prefix/PREFIX/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -Ee 's,"g?cc","${CC}",' \
		${WRKSRC}/mktool.c

.include <bsd.port.mk>
