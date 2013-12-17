# Created by: D'Arcy J.M. Cain <darcy@druid.net>
# $FreeBSD$

PORTNAME=	generate
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@druid.net
COMMENT=	Simple text pre-processor

USES=		gmake

PLIST_FILES=	bin/generate bin/rgenerate \
		man/man1/generate.1.gz

MAKE_ARGS+=	MANDIR=${STAGEDIR}${MAN1PREFIX}/man \
		BINDIR=${STAGEDIR}${PREFIX}/bin

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS *=,CFLAGS +=,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
