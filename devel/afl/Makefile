# Created by: Xin Li <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	afl
PORTVERSION=	0.71b
CATEGORIES=	devel
MASTER_SITES=	http://lcamtuf.coredump.cx/afl/releases/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	American Fuzzy Lop, a fuzzer

LICENSE=	APACHE20

USES=		gmake tar:tgz

BINFILES=	bin/afl-gcc bin/afl-showmap bin/afl-fuzz lib/afl/afl-as

post-install:
	@for f in ${BINFILES}; do \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/$${f}; \
	done

.include <bsd.port.mk>
