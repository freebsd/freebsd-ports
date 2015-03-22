# Created by: D'Arcy J.M. Cain <darcy@druid.net>
# $FreeBSD$

PORTNAME=	generate
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.druid.net/darcy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple text pre-processor

USES=		gmake tar:tgz

MAKE_ARGS=	BINDIR=${STAGEDIR}${PREFIX}/bin \
		MANDIR=${STAGEDIR}${PREFIX}/man

PLIST_FILES=	bin/generate bin/rgenerate man/man1/generate.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS *=,CFLAGS +=,' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
